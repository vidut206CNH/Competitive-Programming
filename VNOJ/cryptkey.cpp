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
const int MAXN1 = 5e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
int a[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int k,x;
		cin >> k;
		x = k;
		vector<int> p;
		for(int i = 2; i*i <= k; ++i) {
			if(k%i) continue;
			int pro = 1;
			while(k%i == 0) {
				pro *= i;
				k /= i;
			}
			p.push_back(pro);
		}
		if(k > 1 || p.empty()) p.push_back(k);
		
		vector<int> b(sz(p), 0);
		for(int i = 0; i < sz(b); ++i) {
			for(int j = 1; j <= n; ++j) {
				if(a[j]%p[i]) continue;
				
				b[i] = gcd(a[j], b[i]);
			}
		}
		
		bool can = true;
		for(int d : b) {
			if(d == 0) can = false;
			else can &= (x%d == 0);
		}
		
		cout << (can ? "YES\n" : "NO\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}