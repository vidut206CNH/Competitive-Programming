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
int t;
int m,n;
int minX,minY,maxX, maxY;


int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> m >> n;
		minX = minY = MOD;
		maxX = maxY = -MOD;
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				char c;
				cin >> c;
				if(c == 'B') {
					minX = min(minX, i + j);
					maxX = max(maxX, i + j);
					minY = min(minY, i - j);
					maxY = max(maxY, i - j);
				}
			}
		}
		
		int best = MOD;
		int resx = 1, resy = 1;
		
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				int X = i + j;
				int Y = i - j;
				
				int tmp = 0;
				tmp = max(tmp, X - minX);
				tmp = max(tmp, maxX - X);
				tmp = max(tmp, maxY - Y);
				tmp = max(tmp, Y - minY);
				
				if(best > tmp) {
					best = tmp;
					resx = i;
					resy = j;
				}
			}
		}
		//db(best);
		cout << resx << " " << resy << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}