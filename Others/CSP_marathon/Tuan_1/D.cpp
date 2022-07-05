/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;


int m,n, H, W;
pii st[4*MAXN2];
pii segt[4*MAXN2];
pii S[MAXN2];
int cnt[MAXN2];
vector<vector<int> > a;
vector<int> BIT[MAXN2], f[MAXN2];


pii comb(const pii &A, const pii &B) {
	if(A.fi == B.fi) return {A.fi, A.se + B.se};
	
	if(A.se > B.se) {
		return {A.fi, A.se - B.se};
	}
	
	else if(A.se < B.se) {
		return {B.fi, B.se - A.se};
	}
	
	else return {0, 0};
	
	
}

void build1(int row, int id, int l, int r) {
	int idx = row*n*4;
	if(l == r) {
		st[idx + id].fi = a[row][l];
		st[idx + id].se = 1;
		return;
	}
	
	int mid = (l + r) >> 1;
	build1(row, id << 1, l, mid);
	build1(row, id << 1|1, mid + 1, r);
	
	st[idx + id] = comb(st[idx + (id << 1)], st[idx + (id <<1|1)]);
}


void get1(int row, int id, int l, int r, int u, int v, pii &X) {
	
	int idx = row*n*4;
	
	if(u <= l && r <= v) {
		X = comb(X, st[idx + id]);
		return;
	}
	
	int mid = (l + r) >> 1;
	if(u <= mid) get1(row, id << 1, l, mid, u, v, X);
	if(mid + 1 <= v) get1(row, id << 1|1, mid + 1, r, u, v, X);
	
}


void update(int X, int pos, int val) {
	pos = lower_bound(BIT[X].begin(), BIT[X].end(), pos) - BIT[X].begin() + 1;
	for(;pos <= sz(BIT[X]); pos += (pos & -pos)) f[X][pos] += val;
	
}

int get(int X, int pos) {
	auto it = lower_bound(BIT[X].begin(), BIT[X].end(), pos);
	if(*it != pos) --it;
	pos = it - BIT[X].begin() + 1;
	int res = 0;
	for(;pos > 0; pos -= (pos & -pos)) res += f[X][pos];
	
	return res;
}




void build2(int id, int l, int r) {
	if(l == r) {
		segt[id] = S[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build2(id << 1, l, mid);
	build2(id << 1|1, mid + 1, r);
	segt[id] = comb(segt[id << 1], segt[id << 1|1]);
}


void get2(int id, int l, int r, int u, int v, pii &X) {
	if(u <= l && r <= v) {
		X = comb(X, segt[id]);
		return;
	}
	
	int mid = (l + r) >> 1;
	if(u <= mid) get2(id << 1, l, mid, u, v, X);
	if(mid +1 <= v) get2(id <<1|1, mid + 1, r, u, v, X);
}



int main() {
	fast_cin();
	
	cin >> m >> n >> H >> W;
	vector<int> values;
	for(int i = 0; i < m; ++i) {
		vector<int> tmp;
		int x;
		for(int j = 0; j < n; ++j) {
			cin >> x;
			values.push_back(x);
			tmp.push_back(x);
		}
		
		a.push_back(tmp);
	}
	
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	
	
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			a[i][j] = lower_bound(values.begin(), values.end(), a[i][j]) - values.begin() + 1;
		}
	}
	
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			BIT[a[i][j]].emplace_back(i);
		}
	}
	
	for(int i = 1; i < m*n; ++i) {
		
		sort(BIT[i].begin(), BIT[i].end());
		
		BIT[i].resize(unique(BIT[i].begin(), BIT[i].end()) - BIT[i].begin());
		f[i].resize(sz(BIT[i]) + 5);
		
	}
	
	
	for(int i = 0; i < m; ++i) {
		build1(i, 1, 0, n - 1);
	}
	
	int res = 0;
	
	
	
	
	for(int r = 0; r < m; ++r) {
		for(int c = 0; c <= W - 2; ++c) {
			update(a[r][c], r, +1);
		}
	}
	
	for(int c = W - 1; c < n; ++c) {
		
		for(int r = 0; r < m; ++r) {
			update(a[r][c], r, +1);
			pii val = {0, 0};
			get1(r, 1, 0, n - 1, c - W + 1, c, val);
			S[r] = val;
		}
		
		build2(1, 0, m - 1);
		
		for(int r = H - 1; r < m; ++r) {
			pii val;
			get2(1, 0, m - 1, r - H + 1, r, val);
			
			if(val.fi == 0) continue;
			
			int v = get(val.fi, r) - get(val.fi, r - H);
			if(2*v > H*W) res++;
		}
		
		for(int r = 0; r < m; ++r) {
			update(a[r][c - W + 1], r, -1);
		}
		
	}
	
	
	cout << (m - H + 1)*(n - W + 1) - res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}