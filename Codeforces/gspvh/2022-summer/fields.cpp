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

int t;
int n,lim;
long long cost;
int pos[MAXN1];
long long f[MAXN1];

int main() {
	fast_cin();
	
	freopen("fields.inp", "r", stdin);
	freopen("fields.out", "w", stdout);
	
	cin >> t;
	cin >> n >> lim >> cost;
	for(int i = 1; i <= n; ++i) cin >> pos[i];
	sort(pos + 1, pos + n + 1);
	for(int i = 1; i <= n; ++i) f[i] = f[i - 1] + pos[i];
	
	int low = 0, high = n, res = 0;
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		bool ok = false;
		
		if(mid&1) {
			for(int i = (mid + 1)/2; i + (mid/2) <= n; ++i) {
				
				long long sum = 1LL*(mid/2)*pos[i] - (f[i - 1] - f[i - mid/2 - 1]);
				sum += ((f[i + mid/2] - f[i]) - 1LL*(mid/2)*pos[i]);
				ok |= (sum <= cost);
				 				
			}
			
		}
		
		else {
			for(int l = mid/2; l + mid/2 <= n; ++l) {
				int val = (pos[l + 1] + pos[l]) >> 1;
				long long sum = (1LL*(mid/2)*val  - (f[l] - f[l - mid/2]));
				sum += ((f[l + mid/2] - f[l]) - (1LL*(mid/2)*val));
				ok |= (sum <= cost);
				
			}
		}
		
		if(ok) {
			res = mid;
			low = mid + 1;
		}
		
		else high = mid - 1;
		
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}