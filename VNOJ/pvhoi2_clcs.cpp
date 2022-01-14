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
const int MAXN1 = 3e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,h,w;
int a[MAXN1][MAXN1];
int f[MAXN1][MAXN1];


int get(const int& x,const int& y) {
	return f[x][y]  - f[x-h][y] - f[x][y-w] + f[x-h][y-w];
}

signed main() {
	fast_cin();
	
	cin >> m >> n >> h >> w;
	
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	
	int l=1,r = m*n,res;
	while(l <= r) {
		int mid = (l+r) >> 1;
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=n;++j) {
				f[i][j] = (a[i][j] >= mid);
				f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1]; 
			}
		}
		bool good = 0;
		
		for(int i=h;i<=m;++i) {
			for(int j=w;j <= n;++j) {
				good |= (get(i,j) >= h*w - (h*w + 1)/2 + 1);
			}
		}
		if(good) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
		
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}