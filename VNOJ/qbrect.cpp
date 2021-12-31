/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int m,n;

int a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];
int L[MAXN1];
int R[MAXN1];

signed main() {
	fast_cin();
	
	cin >> m >> n;
	for(int i=1;i<=m;++i) {
		for(int j=1;j <= n;++j) cin >> a[i][j];
 	}
 	
 	for(int c=1;c <= n;++c) {
 		for(int r=1;r<=m;++r) {
 			if(a[r][c]) f[r][c] = f[r-1][c] + 1;
 			//cout << a[r][c] << " ";
 		}
 		//cout << "\n";
 	}
	
	int ans = 0;
	
	for(int r=1;r <= m;++r) {
		stack<int> d;
		for(int c = 1;c <= n;++c) {
			//cout << f[r][c] << " ";
			while(!d.empty() && f[r][d.top()] >= f[r][c]) {
				d.pop();
			}
			
			if(d.empty()) {
				L[c] = c;
			} else L[c] = c - d.top();
			
			d.push(c);
			
			
		}
		
		while(!d.empty()) d.pop();
		
		for(int c=n;c >= 1; --c) {
			while(!d.empty() && f[r][d.top()] >= f[r][c]) {
				d.pop();
			}
			
			if(d.empty()) {
				R[c] = n + 1 - c;
			} else R[c] = d.top() - c;
			
			d.push(c);
	
			ans = max(ans, (R[c] + L[c] - 1)*f[r][c]);
			//cout << R[c] << " ";
		}
		
		//cout << "\n";
	}
	
	cout << ans;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}