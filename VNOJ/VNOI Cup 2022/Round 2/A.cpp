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

int n,m;
pair<pii,int> a[MAXN1];


int main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi.se >> a[i].fi.fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	bool ok = false;
	for(int i = 1; i <= n; ++i) {
		ok |= (a[i].fi.se > a[1].fi.fi);
		
		if(ok) {
			cout << "YES\n";
			cout << a[i].se << " " << a[1].se << "\n";
			return 0;
		}
	}
	
	cout << "NO\n";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}