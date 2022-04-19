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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m;
int a[MAXN1];
int b[MAXN1];
int fa[MAXN1], fb[MAXN1];

int p[MAXN1][2];
int dp[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		fa[i] = fa[i - 1] + a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
		fb[i] = fb[i - 1] + b[i];
	}
	
	int la = 1, lb = 1, lim = 0;
	
	while((la <= n) && (lb <= m)) {
		if(a[la] < b[lb]) {
			++la;
			continue;
		}
		
		if(a[la] > b[lb]) {
			++lb;
			continue;
		}
		
		++lim;
		p[lim][0] = la;
		p[lim][1] = lb;
		++la;
		++lb;
	}
	
	for(int i = 1; i <= lim; ++i) {
		int sum1 = fa[p[i][0]] - fa[p[i - 1][0]];
		int sum2 = fb[p[i][1]] - fb[p[i - 1][1]];
		
		dp[i] = max(sum1, sum2) + dp[i - 1];
	}
	
	int sum1_last = fa[n] - fa[p[lim][0]];
	int sum2_last = fb[m] - fb[p[lim][1]];
	
	cout << dp[lim] + max(sum1_last, sum2_last);
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}