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
const int MAXN1 = 2005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];


void sub1() {
	int res = 0;
	
	for(int mask = 1; mask < (1 << n); ++mask) {
		if(__builtin_popcount(mask) == 1) continue;
		vector<int> d;
		for(int pos = 0; pos < n; ++pos) {
			if(mask >> pos & 1) {
				d.push_back(a[pos + 1]);
			}
		}
		int max1 = 0, max2 = 0;
		bool can = true;
		
		for(auto x : d) {
			if(max1 < max2) swap(max1, max2);
			if(x > max1) {
				max1 = x;
				continue;
			}
			if(x > max2) {
				max2 = x;
				continue;
			}
			
			can = false;
			break;
		}
		
		if(can) {
			res++;
		}
	}
	
	cout << res << "\n";
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sub1();

	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}