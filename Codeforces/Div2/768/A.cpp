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


signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n+1), b(n+1);
		for(int i=1;i<=n;++i) cin >> a[i];
		for(int i=1;i<=n;++i) cin >> b[i];
		for(int i=1;i<=n;++i) {
			if(a[i] < b[i]) swap(a[i], b[i]);
		}
		
		cout << *max_element(a.begin() + 1, a.end())*(*max_element(b.begin() + 1, b.end())) << "\n";
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}