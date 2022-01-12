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

int t;
int a[105];
int cnt[35];
signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		int n,l;
		cin >> n >> l;
		int d = 0;
		memset(cnt, 0, sizeof cnt);
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			for(int k=0;k<l;++k) {
				if(a[i] >> k & 1) cnt[k]++;
			}
		}
		for(int i=0;i<l;++i) {
			if(cnt[i] > n/2) d |= (1LL << i);
		}
		cout << d << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}