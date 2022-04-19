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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
int a[MAXN1];
int b[MAXN1];
int pos[MAXN1];
int c[MAXN1];
vector<int> dp;

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
		c[i] = pos[b[i]];
	}
	
	for(int i = 1; i <= n; ++i) {
		int id = lower_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
		if(id == sz(dp)) {
			dp.push_back(c[i]);
		}
		else dp[id] = c[i];
	}
	
	cout << sz(dp);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}