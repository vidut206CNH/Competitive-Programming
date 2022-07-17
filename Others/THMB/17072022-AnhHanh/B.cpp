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
vector<int> Men[2], Women[2];

int main() {
	fast_cin();
	
	cin >> t;
	int n,m;
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		bool state = (x < 0 ? 0 : 1);
		Men[state].push_back(abs(x));
	}
	
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		bool state = (x < 0 ? 1 : 0);
		Women[state].push_back(abs(x));
	}
	
	for(int i = 0; i < 2; ++i) {
		sort(Men[i].begin(), Men[i].end());
		sort(Women[i].begin(), Women[i].end());
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}