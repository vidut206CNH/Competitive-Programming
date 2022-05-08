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
		int x,y;
		cin >> x >> y;
		
		if(y%x) {
			cout << "0 0\n";
			continue;
		}
		y /= x;
		if(y == 1) {
			cout << "1 1\n";
			continue;
		}
		
		set<int> st;
		int cnt = 0;
		for(int i = 2; i*i <= y; ++i) {
			if(y%i) continue;
			
			st.insert(i);
			while(y%i == 0) {
				cnt++;
				y /= i;
			}
		}
		
		if(y > 1) {
			cnt++;
			st.insert(y);
		} 
		
		if(sz(st) == 1) {
			cout << cnt << " " << *st.begin() << "\n";
		}
		else cout << "0 0\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}