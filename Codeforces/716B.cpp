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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int cnt[200];

signed main() {
	fast_cin();
	
	
	string s;
	cin >> s;
	if(sz(s) < 26) {
		cout << -1;
		exit(0);
	}
	
	int cur = 0,hid = 0;
	bool good = 0;
	
	int l = 0, r = 0;
	while(r < sz(s)) {
		if(s[r] == '?') hid++;
		if(s[r] != '?' && cnt[s[r]] == 0) {
			cur++;
		}
		cnt[s[r]]++;
		if(cur + hid == 26) {
			bool ok = 1;
			db(l);
			db(r);
			for(int i=(int)'A';i <= (int)'Z';++i) ok &= (cnt[i] <= 1);
			if(ok) {
				good = 1;
				break;
			}
		}
		if(r >= 25) {
			if(s[l] == '?') hid--;
			else cnt[s[l]]--;
			
			if(s[l] != '?' && cnt[s[l]] == 0) cur--;
			l++;
		}
		r++;
	}
	
	if(good) {
		int pos = (int)'A';
		for(;l <= r;++l) {
			if(s[l] == '?') {
				while(pos <= (int)'Z' && cnt[pos]) pos++;
				s[l] = char(pos); 
				pos++;
			}
		}
	}
	for(int i=0;i<sz(s);++i) {
		if(s[i] == '?') s[i] = 'A';
	}
	
	if(good) cout << s;
	else cout << -1;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}