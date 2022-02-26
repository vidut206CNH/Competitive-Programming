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

string s;
int cnt[35];
int f[MAXN2];

int pow(int a, int b)  {
	int res = 1;
	while(b) {
		if(b&1) res = res*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	
	return res;
}


signed main() {
	fast_cin();
	
	cin >> s;
	for(auto c : s) {
		cnt[c - 'A']++;
	}
	int np = 0, rem = 0;
	for(int i = 0; i < 26; ++i) {
		np += cnt[i]/2;
		rem += (cnt[i]%2);
	}
	
	
	if(rem > 1) {
		cout << 0;
		exit(0);
	}
	
	f[0] = 1;
	for(int i = 1; i < MAXN2; ++i) {
		f[i] = f[i - 1]*i%MOD;
	}
	int ans = f[np];
	
	for(int i = 0; i < 26; ++i) {
		if(cnt[i]/2 == 0) continue;
		ans = ans*pow(f[cnt[i]/2], MOD - 2)%MOD;
		
	}
	
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}