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

int n,m, p, y;

int main() {
	fast_cin();
	
	freopen("JOSEPHUS.INP", "r", stdin);
	freopen("JOSEPHUS.OUT", "w", stdout);
	
	cin >> n >> m;
	cin >> p >> y;
	
	int f = 0;
	for(int i = 2; i <= n; ++i) f = (f + m)%i;
	
	
	cout << (f + p)%n << " " << (y - f + n)%n;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}