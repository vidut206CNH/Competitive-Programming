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
const int MAXN1 = 1e7+5;
const int MAXN2 = 1e6+5;

int n;
int f[MAXN1];
int cnt[MAXN1];

void pre(int d) {
	for(int i=1;i*i <= d;++i) {
		for(int j=i*i;j <= d;j += i*i) {
			f[j] = j/(i*i);
		}
	}
}

signed main() {
	fast_cin();
	cin >> n;
	pre(n);
	int ans = 0;
	for(int i=1;i<=n;++i) {
		ans += cnt[f[i]];
		cnt[f[i]]++;
	}
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}