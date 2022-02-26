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
const int MAXN1 = 2e5+3;
const int MAXN2 = 1e7+3;
const int inf = 1e18;

int n;
int a[MAXN1];
int cnt[MAXN2];

signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j*j <= a[i]; ++j) {
			if(a[i]%j) continue;
			if(j*j != a[i]) cnt[a[i]/j]++;
			cnt[j]++;
		}
	}
	
	for(int i = *max_element(a + 1, a + n + 1); i >= 1; --i) {
		if(cnt[i] >= 2) {
			cout << i;
			exit(0);
		}	
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}