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
const int MAXN1 = 1005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;
int cost[MAXN1];
vector<int> b[MAXN1];
bool mark[MAXN1];

void sub1() {
	
	int res = 0;
	
	for(int mask = 0; mask < (1 << n); ++mask) {
		int sum1 = 0, sum2 = 0;
		
		for(int i = 0; i < n; ++i) {
			if(mask >> i & 1) {
				mark[i + 1] = true;
				sum1 += cost[i + 1];
			}
			else mark[i + 1] = false;
		}
		//db(mask);
		
		for(int i = 1; i <= m; ++i) {
			bool ok = true;
			
			for(int j = 1; j < sz(b[i]); ++j) {
				ok &= (mark[b[i][j]]);
			}
			
			sum2 += (ok ? b[i][0] : 0);
		}
		//db(sum2);
		//cerr << "\n";
		res = max(sum2 - sum1, res);
	}
	
	cout << res;
}

void sub2() {
	
	
	int res = 0;
	
	for(int mask = 0; mask < (1 << m); ++mask) {
		//db(mask);
		for(int i = 1; i <= n; ++i) mark[i] = false;
		
		int sum1 = 0,sum2 = 0;
		
		for(int i = 0; i < m; ++i) {
			if(mask >> i & 1) {
				sum2 += b[i + 1][0];
				for(int j = 1; j < sz(b[i + 1]); ++j) {
					mark[b[i + 1][j]] = true;
				}
			}
		}
		
		for(int i = 1; i <= n; ++i) {
			sum1 += (mark[i] ? cost[i] : 0);
		}
		
		res = max(res, sum2 - sum1);
	}
	
	cout << res;
}

signed main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> cost[i];
	
	for(int i = 1; i <= m; ++i) {
		int t, ss;
		cin >> t >> ss;
		vector<int> tmp;
		tmp.push_back(t);
		for(int j = 1; j <= ss; ++j) {
			int x;
			cin >> x;
			tmp.push_back(x);
		}
		b[i] = tmp;
	}
	
	
	if(n <= 20) {
		sub1();		
	}
	
	else if(m <= 20) {
		sub2();
	}
	
	else cout << 0;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}