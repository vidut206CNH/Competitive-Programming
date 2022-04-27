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

int n;
string s;
int a[30];
char res[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> s;
	for(int i = 0; i < 26; ++i) cin >> a[i];
	bool bad = false;
	
	for(int i = 0; i < n; ++i) {
		if(s[i] != '?') {
			a[s[i] - 'a']--;
			res[i] = s[i];
		}
	}
	
	for(int i = 0; i < n; ++i) {
		if(s[i] == '?') {
			for(int c = 0; c < 26; ++c) {
				if(a[c] > 0) {
					a[c]--;
					res[i] = (c + 'a');
					break;
				}
				
				if(c == 25) {
					bad = true;
				}
			}
		}
	}
	
	
	for(int i = 0; i < 26; ++i) {
		bad |= (a[i] != 0);
	}
	
	if(bad) {
		cout << -1;
		return 0;
	}
	for(int i = 0; i < n; ++i) cout << res[i];
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}