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


signed main() {
	fast_cin();
	
	int n;
	cin >> n;
	bool find = 0;
	int pre = 0;
	
	int l=1,r=n-1;
	int add = 0;
	while(l <= r) {
		int mid = (l+r) >> 1;
		cout << "+ " << mid << "\n";
		fflush(stdout);
		int rep;
		cin >> rep;
		pre = rep;
		if(pre == 1) {
			r = mid - 1;
		} else l = mid + 1;
		add = mid;
	}
	cout << "! " << n - add + pre << "\n";
		
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}