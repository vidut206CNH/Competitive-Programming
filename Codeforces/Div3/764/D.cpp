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


int t,n,k;
char a[MAXN1];
int cnt[30];

signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		cin >> n >> k;
		int odd = 0;
		cin.ignore();
		memset(cnt ,0, sizeof cnt);
		
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			cnt[a[i] - 'a']++;
		}
		int d = 0;
		for(int i = 0; i <= 25;++i) {
			d += (cnt[i]/2);
			odd += (cnt[i]%2 != 0);
		}
		/*db(odd);
		cerr << "\n";*/
		int res = d/k;
		d -= res*k;
		d *= 2;
		d += odd;
		cout << res*2 + (d >= k) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}