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

int n,m;
long long s;
int a[40];
vector<int> X[40];

int main() {
	fast_cin();
	cin >> n >> m >> s;
	
	for(int i = 0; i < n; ++i) cin >> a[i];
	int le = n/2, ri = n - le;
	
	for(int mask = 0; mask < (1 << le); ++mask) {
		long long sum = 0;
		for(int i = 0; i < le; ++i) {
			if(mask >> i & 1) {
				sum += a[i];
			}
		}
		int d = __builtin_popcount(mask);
		X[d].push_back(sum);
	}
	
	for(int i = 0; i < le; ++i) sort(X[i].begin(), X[i].end());
	
	long long res = 0;
	for(int mask = 0; mask < (1 << ri); ++mask) {
		long long sum = 0;
		for(int i = 0; i < ri; ++i) {
			if(mask >> i & 1) {
				sum += a[i + le];
			}
		}
		
		int d = __builtin_popcount(mask);
		if(d > m) continue;
		res += (upper_bound(X[m - d].begin(), X[m - d].end(), s - sum) - lower_bound(X[m - d].begin(), X[m - d].end(), s - sum));
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}