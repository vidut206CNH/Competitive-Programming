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
string s;
int dist[11][11];

void calc(int x, int y) {
	memset(dist, -1, sizeof dist);
	
	for(int a = 0; a < 10; ++a) {
		for(int b = 0; b < 10; ++b) {
			for(int cx = 0; cx < 10; ++cx) {
				for(int cy = 0; cy < 10; ++cy) {
					if(cx == 0 && cy == 0) continue;
					if((a + x*cx + y*cy)%10 == b) {
						if(dist[a][b] != -1) dist[a][b] = min(dist[a][b], cx + cy);
						else dist[a][b] = cx + cy;
					}
				}
			}
		}
	}
	
}



signed main() {
	fast_cin();
	
	cin >> s;
	n = sz(s);
	s = '0' + s;
	
	for(int x = 0; x < 10; ++x) {
		for(int y = 0; y < 10; ++y) {
			calc(x,y);
			int res = 0;
			for(int i = 1; i < n; ++i) {
				int a = s[i] - '0';
				int b = s[i + 1] - '0';
				if(dist[a][b] == -1) {
					res = -1;
					break;
				}
				res += (dist[a][b] - 1);
			}
			
			cout << res << " \n"[y == 9];
		}
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}