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

const long long MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const long long BASE = 31;

int n;
string s[MAXN2];
long long P[MAXN2];
vector<long long> h[MAXN2];

int main() {
	fast_cin();
	
	P[0] = 1;
	for(int i = 1; i < MAXN2; ++i) P[i] = P[i - 1]*BASE%MOD;
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '0' + s[i];
		
		h[i].resize(sz(s[i]));
		
		for(int j = 1; j < sz(s[i]); ++j) h[i][j] = (h[i][j - 1]*BASE + s[j] - 'a')%MOD;
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
