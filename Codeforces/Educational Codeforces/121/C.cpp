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

int t;
int p[105];
int h[105];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;++i) cin >> p[i];
		for(int i=1;i<=n;++i) cin >> h[i];
		int sum = 0;
		for(int i=1;i<=n;++i) {
			for(int j=i-1;j>=0;--j) {
				if(h[j] + p[i] - p[j] >= h[i]) {
					if(p[i] - p[j] >= h[i]) {
						sum += (h[i] + 1)*h[i]/2;
						break;
					}
					int d = max(h[i],h[i-1] + p[i] - p[i-1]);
					sum += ((d + 1)*d/2 - (h[i-1]+1)*h[i-1]/2);
					h[i] = d;
					break;
				}
			}
		}
		cout << sum << "\n";
		
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}