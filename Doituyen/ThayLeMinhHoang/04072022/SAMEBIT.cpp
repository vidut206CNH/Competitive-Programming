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

const int MOD = 123456789;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;




long long power(long long A, long long B) {
	long long res = 1;
	while(B) {
		if(B&1) res = res*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return res;
}

long long calc(int p) {
	if(p == 0) return 1;
	if(p == 1) return 5;
	
	if(p%2 == 1) {
		long long g = calc(p/2);
		return (g + power(2, 2*(p/2 + 1))*g%MOD)%MOD;
	}
	
	else {
		long long g = calc(p/2 - 1);
		return (g + power(2, p) + power(2, 2*(p/2 + 1))*g%MOD)%MOD;
	}
}

int main() {
	fast_cin();
	
	freopen("SAMEBIT.INP", "r", stdin);
	freopen("SAMEBIT.OUT", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n <= 1) {
			cout << 0 << "\n";
			continue;
		}
		if(n == 2) {
			cout << 1 << "\n";
			continue;
		}
		
		int p = (n + 1)/2 - 1;
		
		if(n%2 == 0) {
			cout << calc(p) << "\n";
		}
		
		if(n%2) {
			cout << 2*calc(p - 1)%MOD << "\n";
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}