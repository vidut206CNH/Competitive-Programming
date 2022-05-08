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
const int inf = 1e18;

int n;
char a[35];

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < 5; ++i) cin >> a[i];
	
	int hour = (a[0] - '0')*10 + a[1] - '0';
	
	int min = (a[3] - '0')*10 + a[4] - '0';
	
	hour += min/60;
	min %= 60;
	
	hour %= n;
	
	
	string res = "";
	res += ('0' + hour/10);
	res += ('0' + hour%10);
	res += ':';
	
	res += ('0' + min/10);
	res += ('0' + min%10);
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}