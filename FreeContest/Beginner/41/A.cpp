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

int k;
string s;

signed main() {
	fast_cin();
	
	
	cin >> k >> s;
	if(s == "0" || s == "1") {
		
		return cout << 0, 0;
		
	}
	//reverse(s.begin(), s.end());
	int cnt = 0;
	
	while(true) {
		int val = 0;
		for(int i = 0; i < sz(s); ++i) {
			val += 1LL*(s[i] - '0')*(1LL << (sz(s) - i - 1));
		}
		
		if(val <= k) break;
		
		cnt++;
		bool del = false;
		for(int i = 1; i < sz(s); ++i) {
			if(s[i] == '1') {
				del = true;
				s.erase(i, 1);
				break;
			}
		}
		
		if(!del) s.erase(--s.end());
	}
	
	cout << cnt;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}