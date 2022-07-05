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

int t,n;
char a[MAXN1];
map<pii, int> mp;

int main() {
	fast_cin();
	cin >> t;
	while(t--) {
		mp.clear();
		pii cur = {0, 0};
		mp[cur] = 0;
		cin >> n;
		int best = MOD, l, r;
		for(int i = 1; i <= n; ++i) {
			char c;
			cin >> c;
			if(c == 'L') cur.se--;
			if(c == 'R') cur.se++;
			if(c == 'U') cur.fi++;
			if(c == 'D') cur.fi--;
			
			if(mp.count(cur)) {
				int diff = i - mp[cur];
				if(diff < best) {
					best = diff;
					l = mp[cur] + 1;
					r = i;
				}
			}
			
			mp[cur] = i;
		}
		
		if(best == MOD) cout << "-1\n";
		else cout << l << " " << r << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}