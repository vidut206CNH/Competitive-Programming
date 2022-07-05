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
int X[MAXN1];
int Y[MAXN1];

int main() {
	fast_cin();
	
	while(cin >> n) {
		if(n == 0) break;
		for(int i = 1; i <= n; ++i) cin >> X[i] >> Y[i];
		X[n + 1] = X[1];
		X[0] = X[n];
		Y[n + 1] = Y[1];
		Y[0] = Y[n];
		long long res = 0;
		
		for(int i = 1; i <= n; ++i) {
			res += 1LL*X[i]*(Y[i + 1] - Y[i - 1]);
		}
		
		cout << fixed << setprecision(2) << abs(1.0*res/2) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}