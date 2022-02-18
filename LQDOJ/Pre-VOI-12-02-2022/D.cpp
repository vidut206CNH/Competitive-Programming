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
const int MAXN1 = 105;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
int X[MAXN1];
int Y[MAXN1];
int Z[MAXN1];

int val[(1 << 22) + 5][3];

void sub1() {
	for(int mask = 1; mask < (1 << n); ++mask) {
		int xmax = -MOD, ymax = -MOD, zmax = -MOD;
		int	xmin = MOD, ymin = MOD, zmin = MOD;
		
		for(int i = 0; i < n; ++i) {
			if(mask >> i & 1) {
				xmax = max(xmax, X[i + 1]);
				ymax = max(ymax, Y[i + 1]);
				zmax = max(zmax, Z[i + 1]);
				
				xmin = min(xmin, X[i + 1]);
				ymin = min(ymin, Y[i + 1]);
				zmin = min(zmin, Z[i + 1]);
			}
		}
		
		val[mask][0] = xmax - xmin;
		val[mask][1] = ymax - ymin;
		val[mask][2] = zmax - zmin;
		
	}
	
	int res = inf;
	
	for(int mask = 1; mask < (1 << n); ++mask) {
		
		int d = ((1 << n) - 1)^mask, best = inf;
			
		for(int s = mask; s; s = (s - 1) & mask) {
			if(s == mask) continue;
			
			int g = mask^s;
			
			for(int i = 0; i < 3; ++i) {
				for(int j = 0; j < 3; ++j) {
					if(i == j) continue;
					for(int k = 0; k < 3; ++k) {
						if(i == k || j == k) continue;
						
						best = min(best, val[d][i] + val[s][j] + val[g][k]);
						
					}
				}
			}
		}
		
		res = min(res, best);
	}
	
	cout << res;
}



signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i<= n; ++i) {
		cin >> X[i] >> Y[i] >> Z[i];
	}
	
	sub1();
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}