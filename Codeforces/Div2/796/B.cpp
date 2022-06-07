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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int t;
int n;
int a[MAXN1];

int main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> n;
		int best = MOD;
		int res  = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(a[i]%2 == 0) res++;
			if(a[i]%2) best = 0;
			int cnt = 0;
			while(a[i]%2 == 0) {
				a[i] /= 2;
				cnt++;
			}
			
			best = min(best, cnt);
		}
		
		res += (best == 0 ? best : best - 1);
		
		cout << res << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}