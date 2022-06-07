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

int t;
int n;
char a[MAXN1];
int cnt[30];

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j <= 1; ++j) {
				string s;
				cin >> s;
				for(auto x : s) {
					cnt[x - 'a']++;
				}
			}
		}
		
		string s;
		cin >> s;
		for(auto x : s) cnt[x - 'a'] += 1;
		
		int res = 0;
		for(int i = 0; i <= 25; ++i) {
			if(cnt[i]&1) {
				res = i;
				break;
			}
		}
		
		cout << (char)(res + 'a') << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}