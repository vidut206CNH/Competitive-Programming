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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int a[MAXN1];
int b[MAXN1];
int cnt[2*MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int mn = inf, mx = -inf;
		vector<int> mx,mn;
		for(int i = 1; i <= n/2; ++i) {
			if(a[i] < a[n - i + 1]) swap(a[i], a[n - i + 1]);
			mx.push_back(a[i]);
			mn.push_back(a[n - i + 1]);
			cnt[a[i] + a[n - i + 1]]++;
		}
		
		
		
		
		
		
		//reset
		for(int i = 1; i <= n/2; ++i) {
			cnt[a[i] + a[n - i + 1]]--;
		}
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}