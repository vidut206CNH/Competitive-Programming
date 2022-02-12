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
int a[20];
int f[15];

signed main() {
	fast_cin();
	
	
	cin >> n;
	cin.ignore();
	for(int i=1;i<=n;++i) {
		char c;
		cin >> c;
		a[i] = c - 48;
		for(int val=2;val<=a[i];++val) {
			int d = val;
			for(int k=2; k*k <= d;++k) {
				while(d%k == 0) {
					f[k]++;
					d /= k;
				}
			}
			
			if(d != 1) f[d]++;
		}
	}
	
	for(int i=9;i>=2;--i) {
		while(f[i]) {
			cout << i;
			for(int val = i; val >= 2; --val) {
				int d = val;
				for(int k = 2; k*k <= val; ++k) {
					while(d%k == 0) {
						f[k]--;
						d /= k;
					}
				}
				if(d != 1) f[d]--;
			}
		} 
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}