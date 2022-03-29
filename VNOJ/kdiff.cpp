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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[MAXN1];
int dp[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	deque<int> minn, maxx;
	int lastpos = 0;
	
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		while(!minn.empty() && a[minn.back()] > a[i]) minn.pop_back();
		while(!maxx.empty() && a[maxx.back()] < a[i]) maxx.pop_back();
		
		minn.push_back(i);
		maxx.push_back(i);
		
		while(a[maxx.front()] - a[minn.front()] > k) {
			if(maxx.front() < minn.front()) {
				lastpos = maxx.front();
				maxx.pop_front();
			}
			else {
				lastpos = minn.front();
				minn.pop_front();
			}
		}
		res = max(res, i - lastpos + dp[lastpos]);
		dp[i] = max(i - lastpos, dp[i - 1]);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}