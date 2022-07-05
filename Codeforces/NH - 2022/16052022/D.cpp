/* 
	Author : vidut_206_CNH
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
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;


struct data{
	int tt;
	int type, id, val; 
};

int n,q;
int a[MAXN1];
vector<int> v;
vector<data> query;
int res[MAXN1];
int cnt[MAXN1];

int BIT[3][MAXN1];


void update(int type, int pos, int val) {
	if(type) for(;pos > 0; pos -= (pos & -pos)) BIT[type][pos] += val;
	else for(;pos < MAXN1; pos += (pos & -pos)) BIT[type][pos] += val;
}

int get(int type, int pos) {
	int res = 0;
	if(type) for(;pos < MAXN1; pos += (pos & -pos)) res += BIT[type][pos];
	else for(;pos > 0; pos -= (pos & -pos)) res += BIT[type][pos];
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n >> q;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	for(int i = 0; i < sz(v) - 1; ++i) {
		query.push_back({0, 0, v[i + 1] - v[i], i});
	}
	
	for(int i = 1; i <= n; ++i) {
		int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		cnt[id]++;
	}
	
	
	long long  diff = 0, sizee = sz(v), sum = 0;
	
	for(int i = 0; i < sz(v); ++i) {
		diff += cnt[i]*(sz(v) - i - 1);	
		update(0, i + 1, cnt[i]);
	}

	
	for(int i = 1; i <= q; ++i) {
		int type, id, val = -1;
		cin >> type;
		
		if(type == 1 || type == 2) {
			cin >> id;
		}
		
		else {
			cin >> id >> val;
		}
		
		query.push_back({i, type, id, val});
	}
	
	sort(query.begin(), query.end(), [&](const data& A, const data& B) {
		if(A.id != B.id) return A.id < B.id;
		return A.tt < B.tt;
	});
	
	int pre_id = 0;
	for(auto E : query) {
		
		int tt = E.tt;
		int type = E.type;
		int id = E.id;
		int val = E.val;
		
/*		db(id);
		db(tt);
		cerr << "\n";*/
		
		sum += diff*(id - pre_id);
		
		
		if(type == 0) {
			diff -= get(0, val + 1);
			update(1, val + 1, 1);
			update(2, val + 1, id);
			--sizee;
		}
		
		else if(type == 1) {
			res[tt] = sizee;
			//cout << sizee << "\n";
		}
		
		else if(type == 2) {
			res[tt] = sum;
			//cout << sum << "\n";
		}
		
		else if(type == 3) {
			long long tmp = a[val];
			int p = lower_bound(v.begin(), v.end(), a[val]) - v.begin();
			long long g = get(1, p + 1);
			int m = get(2, p + 1);
/*			db(g);
			db(m);
			cerr << "\n";*/
			tmp = tmp + (sz(v) - p - 1)*id - id*g + m;
			
			res[tt] = tmp;
		}
		
		pre_id = id;
	}
	
	
	for(int tt = 1; tt <= q; ++tt) {
		cout << res[tt] << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}