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
int bit1[20];
int bit2[20];

signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		int l, n;
		cin >> l >> n;
		++n;
		memset(bit1, 0, sizeof bit1);
		memset(bit2, 0, sizeof bit2);
		
		int sum = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		
		for(int i = 0; i < n; ++i) {
			for(int pos = 0; pos < 17; ++pos) {
				if(!(i >> pos & 1)) bit1[pos]++;
				else bit2[pos]++;
			}
		}
		
		int sum1 = n*(n - 1)/2;
		int res = -1;
		
		for(int i = 1; i <= n; ++i) {
			int sum2 = 0;
			for(int pos = 0; pos < 17; ++pos) {
				if(a[i] >> pos & 1) {
					sum2 += bit1[pos]*(1LL << pos);
					sum2 -= bit2[pos]*(1LL << pos);
				}
			}
			if(sum1 + sum2 == sum) {
				res = a[i];
				break;
			}
		}
		cerr << "\n";
		cout << res << '\n';
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}