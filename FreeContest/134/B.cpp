/*
	Author : vidut_206_CNH
	Link problem: 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 2e4+5;
const int MAXN2 = 1e6+5;

int n;
int a[MAXN1];
vector< vector<int> > st(4*MAXN1, vector<int>(105));
vector< vector<int> > m(MAXN1, vector<int>(105));

bool npri[105];

vector<int> comb(const vector<int>& A, const vector<int>& B) {
	vector<int> res(105,0);
	for(int i=2;i<=100;++i) {
		if(!npri[i]) res[i] = (A[i] + B[i])%2;
	}
	return res;
}

void build(int id,int l,int r) {
	if(l == r) {
		st[id] = m[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[id] = comb(st[id << 1], st[id << 1|1]);
}


void update(int id,int l,int r, int& pos, const vector<int>& A) {
	if(l == r) {
		for(int i=2;i<=100;++i) {
			st[id][i] = (st[id][i] + A[i])%2;
		}
		return;
	}
	int mid = (l+r) >> 1;
	
	if(pos <= mid) update(id << 1, l, mid, pos, A);
	else update(id << 1|1, mid + 1, r, pos, A);
	
	st[id] = comb(st[id << 1], st[id << 1|1]);
}

void get(int id,int l,int r,int& u, int& v, vector<int>& ans) {
	if(u <= l && r <= v) {
		for(int i=2;i<=100;++i) {
			ans[i] = (ans[i] + st[id][i])%2;
		}
		return;
	}
	
	int mid = (l+r) >> 1;
	if(u <= mid) get(id << 1, l, mid, u, v, ans);
	if(mid + 1 <= v) get(id << 1|1, mid + 1, r, u, v, ans);
	
} 


signed main() {
	fast_cin();
	
	for(int i=2;i*i<=100;++i) {
		if(!npri[i]) for(int j=i*i;j <= 100; j+= i) npri[j] = 1;
	}
	
	cin >> n;
	
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		
		for(int j=2;j<=100;++j) {
			
			if(!npri[j] && a[i]%j==0) {
				int cnt = 0;
				while(a[i]%j == 0) {
					cnt++;
					a[i] /= j;
				}
				if(cnt%2) {
					m[i][j]++;
				}
			}
			
			
		}
	}
	
	build(1,1,n);
	
	
	
	
	int q;
	cin >> q;
	for(int i=1;i<=n;++i) {
		int t,u,v;
		cin >> t >> u >> v;
		if(t==1) {
			bool bad = 0;
			
			vector<int> tmp(105,0);
			
			get(1,1,n,u,v,tmp);
			for(int j=2;j<=100;++j) {
				//cout << tmp[j] << " ";
				if(!npri[j] && tmp[j]) {
					bad = 1;
					break;
				}
			}
			
			cout << (bad ? "NO\n" : "YES\n");
			
			
		} else {
			vector<int> tmp(105);
			
			for(int j=2;j<=100;++j) {
				if(!npri[j] && v%j==0) {
					int cnt = 0;
					
					while(v%j == 0) {v /= j;cnt++;}
					
					if(cnt%2) {
						tmp[j]++;
					}
				}
			}
			update(1,1,n,u,tmp);
		}
	}
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
