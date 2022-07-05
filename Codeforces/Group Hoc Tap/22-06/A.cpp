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

int n;
vector<int> adj[30];
bool S[30], T[30];

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < sz(s) - 1; j++) {
			adj[s[j] - 'a'].push_back(s[j + 1] - 'a');
			S[s[j] - 'a'] = true;
			T[s[j + 1] - 'a'] = true;
		}
		
		S[s.back() - 'a'] = true;
	}
	
	for(int i = 0; i < 26; ++i) {
		if(S[i] && !T[i]) {
			int u = i;
			while(true) {
				cout << (char)(u + 'a');
				if(sz(adj[u]) == 0) break;
				u = adj[u].back();
			}
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}