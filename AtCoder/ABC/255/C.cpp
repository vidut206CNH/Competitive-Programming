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

int X,A,D,N;

signed main() {
	fast_cin();
	
	cin >> X >> A >> D >> N;
	if(D == 0) {
		cout << abs(X - A);
		exit(0);
	}
	int p = max(0LL, (X - A)/D);
	if(p >= N - 1) {
		cout << abs(X - (A + D*(N - 1)));
		exit(0);
	}
	
	int val1 = abs(A + (p + 1)*D - X);
	int val2 = abs(X - (A + p*D));
	
	cout << min(val1, val2);
	
/*	if(A + (p + 1)*D >= X) {
		cout << min(val1, val2);
	}*/
	
	//else cout << val2;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}