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
const int MAXN1 = 1024;
const int MAXN2 = 505;
const int inf = 1e18;

int m,n;
int a[MAXN2][MAXN2];
int dp[MAXN2][MAXN1];
int trace[MAXN2][MAXN1],choose[MAXN2][MAXN1];

signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	
	
	dp[0][0] = 1;
	choose[0][0] = -1;
	
	for(int i=0;i<m;++i) {
		for(int j=1;j<=n;++j) {
			for(int state = 0; state < MAXN1; ++state) {
				if(dp[i][state] == false ) continue;
				dp[i+1][state ^ (a[i+1][j])] = true;
				choose[i+1][state ^ (a[i+1][j])] = j;
				trace[i+1][state ^ (a[i+1][j])] = choose[i][state];
			}
		}
	}
	
	for(int state=1;state<MAXN1;++state) {
		if(dp[m][state]) {
			vector<int> p;
			for(int j=m;j>=1;--j) {
				int pos = choose[j][state];
				p.push_back(pos);
				state ^= a[j][pos];
			}
			reverse(p.begin(),p.end());
			
			cout << "TAK\n";
			for(auto x : p) cout << x << " ";
			exit(0);
		}
	}
	
	cout << "NIE";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}