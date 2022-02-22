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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e7+5;
const int inf = 1e18;

int cnt[MAXN2];
int n;
int p[MAXN2];

void f(int val, int& res) {
	if(val == 1) return;
	int g = p[val];
	while(val%g == 0) val /= g;
	res *= g;
	f(val, res);
}


signed main() {
	fast_cin();
	
	for(int i = 2; i < MAXN2; ++i) p[i] = i;
	
	for(int i = 2; i*i < MAXN2; ++i) {
		if(p[i] == i) {
			for(int j = i*i; j < MAXN2; j += i) p[j] = min(p[j], i);
		}
	}
	
	cin >> n;
	int ans = 0;
	
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		int res = 1;
		f(x, res);
		ans += cnt[res];
		cnt[res]++;
	}
	
	cout << ans;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}