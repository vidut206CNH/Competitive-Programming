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


long long m,n, k;

int main() {
	fast_cin();
	
	cin >> m >> n >> k;
	
	if(m*n%2 != k%2) {
		cout << 0 << "\n";
		return 0;
	}
	
	int p = (m + n)*2;
	
	for(int i = 1; i <= k; ++i) {
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		p += 2*(u + v  - x - y);
	}
	
	cout << (p - (k + 1)*4)/2;
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}