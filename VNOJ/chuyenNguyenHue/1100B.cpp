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

int n,m;
int f[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> m;
	set<int> st;
	
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		st.insert(x);	
		f[x]++;
		
		if(sz(st) == n) {
			cout << 1;
			for(int j = 1; j <= n; ++j) {
				int last = *(--st.end());
				f[last]--;
				if(f[last] == 0) st.erase(*(--st.end()));
			}
		}
		else cout << 0;
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}