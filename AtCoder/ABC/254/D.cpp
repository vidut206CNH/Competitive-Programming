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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n;
int cnt[MAXN1];
int p[MAXN1];

int main() {
	fast_cin();
	
	cin >> n;
	
	memset(p, -1, sizeof p);
	for(int j = sqrt(n); j >= 1; --j) {
		for(int k = 1; j*j*k <= n; ++k) {
			if(p[j*j*k] == -1) {
				p[j*j*k] = k;
				cnt[k]++;
			}
		}
	}
	
	long long res = 0;
	
	for(int i = 1; i <= n; ++i) {
		res = res + 1LL*cnt[i]*cnt[i];	
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}