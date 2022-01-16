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
const int base = 311;
const int MAXN1 = 5005;
const int MAXN2 = 4e6+5;
const int inf = 1e18;

int n,k;
string a[MAXN1];
int cost[MAXN1][MAXN1];


bool check1() {
	bool ok = 1;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<sz(a[i]) - 1; ++j) {
			ok &= (a[i][j] == a[i][j+1]);
		}
	}
	return ok;
}


//sub1
void sub1() {
	vector<int> cnt[35];
	for(int i=1;i<=n;++i) {
		char c = a[i][0];
		cnt[c - 'a'].push_back(sz(a[i]));
	}
	int res = 0;
	for(int i=0;i <= 25;++i) {
		sort(cnt[i].rbegin(), cnt[i].rend());
		int sum = 0;
		for(int j=1;j < min(sz(cnt[i]), k);++j) {
			sum += (cnt[i][j])*j;
		}
/*		db(i);
		db(sum);
		cerr << "\n";*/
		res = max(sum, res);
	}
	
	cout << res;
	exit(0);
}






void pre_hash(vector<vector<int> >& hashp) {

	
	//vector<vector<int> > hashp(n+1,vector<int>(lim + 5));
	
	
	for(int i=1;i<=n;++i) {
		for(int j=1;j<sz(a[i]);++j) {
			hashp[i][j] = (hashp[i][j-1]*base + a[i][j])%MOD;
		}
	}
	
	
	//calc cost[i][j] lcp(si, sj)
	
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			int l=1,r=min(sz(a[i]),sz(a[j])) - 1,sum = 0;
			while(l <= r) {
				int mid = (l+r) >> 1;
				if(hashp[i][mid] == hashp[j][mid]) {
					sum = mid;
					l = mid + 1;
				} 
				else {
					r = mid - 1;
				}
			}
			
			cost[i][j] = sum;
			cost[j][i] = sum;
/*			db(i);
			db(j);
			db(cost[i][j]);
			cerr << "\n";*/
		}
	}
	
}


//sub4
void sub4() {
	int lim = 1 << n;
	int res = 0;
	for(int state=1;state < (lim);++state) {
		if(__builtin_popcount(state) < 2) continue;
		int sum = 0;
		
		for(int i=0;i<n;++i) {
			if(!(state  >> i & 1)) continue;
			
			
			
			for(int j=i+1;j<n;++j) {
				if(!(state >> j & 1)) continue;
				sum += cost[i+1][j+1];
			}
		}
		
		if(__builtin_popcount(state) == k) {
			res = max(res, sum);
		}
	}
	
	cout << res;
}






//sub3

int f[MAXN1];

void func(int cur, int pos,int& res) {
	if(cur == k + 1) {
		int sum = 0;
		for(int i=1;i<=k;++i) {
			for(int j=i+1;j<=k;++j) {
				sum += cost[f[i]][f[j]];
			}
		}
		res = max(res, sum);
		return;
	}
	for(int i=pos + 1; i <= n;++i) {
		f[cur] = i;
		func(cur+1, i, res);
	}
}


void sub3() {
	int res = 0;
	func(1,0,res);
	cout << res << "\n";
	exit(0);
}




signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	if(check1()) {
		sub1();
	}
	
	int lim = 0;
	for(int i=1;i<=n;++i) {
		lim = max(lim, sz(a[i]));
		a[i] = " " + a[i];
	}
	
	vector<vector<int> > hashp(n+1,vector<int>(lim + 5));
	pre_hash(hashp);
	
	
	if(k == n) {
		
		int sum = 0;
		for(int i=1;i<=n;++i) {
			for(int j=i+1;j <= n;++j) {
				sum += cost[i][j];
			}
		}
		
		cout << sum << "\n";
		exit(0);
	}
	
	if(n <= 20) {
		sub4();
		exit(0);
	}
	
	
	
	sub3();
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}