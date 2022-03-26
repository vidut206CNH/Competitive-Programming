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
int n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		bool zero = false, one = false;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			zero |= (a[i] == 0);
			one |= (a[i] == 1);
		}
		
		if(zero && one) {
			cout << "NO\n";
			continue;
		}
		
		if(one) {
			sort(a + 1, a + n + 1);
			bool good = true;
			for(int i = 2; i <= n; ++i) {
				if(a[i] == 1) continue;
				if(a[i] == 2) {
					good =false;
					break;
				}
				good &= (a[i] != a[i - 1] + 1);
			}
			
			cout << (good ? "YES\n" : "NO\n");
		}
		else cout << "YES\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}