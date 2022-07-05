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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;

int n;
int a[MAXN1];
int f[MAXN1];
int s[MAXN1];
int g[MAXN1];
int cnt[3][3][3];


int main() {
	fast_cin();
	
	
	cin >> n;
	// s - f - g
	memset(cnt, 0, sizeof cnt);
	cnt[0][0][0] = 1;
	long long res = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = (f[i - 1] + a[i])%3;
		s[i] = (a[i]*f[i - 1] + s[i - 1])%3;
		g[i] = f[i]*f[i]%3;
		
		for(int x = 0; x < 3; ++x) {
			for(int y = 0; y < 3; ++y) {
				for(int z = 0; z < 3; ++z) {
					int val = (s[i] - x - y*f[i] + z + 3*3)%3;
					if(!val) {
/*						db(x);
						db(y);
						db(z);
						db(cnt[x][y][z]);
						cerr << "\n";*/
						res += cnt[x][y][z];
					}
				}
			}
		}
/*		db(res);
		cerr << "\n";*/
		cnt[s[i]][f[i]][g[i]]++;
	}
	
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}