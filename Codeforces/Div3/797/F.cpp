/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) ((a)/gcd(a,b)*(b))
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 205;
const int MAXN2 = 1e6+5;

int t,lim;
char a[MAXN1];
int p[MAXN1];
char s[2*MAXN1];
bool ok[MAXN1];

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long ans = 1;
		memset(ok, true, sizeof ok);
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) cin >> p[i];
		
		for(int i = 1; i <= n; ++i) {
			if(!ok[i]) continue;
			lim = 0;
			
			while(ok[i]) {
				ok[i] = false;
				s[++lim] = a[i];
				i = p[i];		
			}
			//db(lim);
			for(int k = lim + 1; k <= 2*lim; ++k) s[k] = s[k - lim];
			
			int best = 0;
			for(int k = 2; k <= lim + 1; k++) {
				bool good = true;
				for(int j = k; j < lim + k; ++j) good &= (s[j] == s[j - k + 1]);
				if(good) {
					best = k - 1;
					break;
				}
			}
			//db(best);
			ans = lcm(ans, 0LL + best);
			//cerr << "\n";
		}
		
		cout << ans << '\n';
	}		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}