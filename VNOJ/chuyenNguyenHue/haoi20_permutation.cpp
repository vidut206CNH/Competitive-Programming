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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

string s;
int a[205];

signed main() {
	fast_cin();
	
	cin >> s;
	int sum = 0;
	int d = 10;
	for(int i=0;i<sz(s);++i) {
		sum += ((int)s[i] - 48);
		a[(int)s[i]]++;
		if((int)s[i]%2 == 0) d = min(d,(int)s[i]);
	}
	if(sum%3 || !a[(int)'0']) cout << -1;
	else {
		for(int i = (int)'9'; i > d; -- i) {
			while(a[i]) {
				cout << (char)i;
				a[i]--;
			}
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}