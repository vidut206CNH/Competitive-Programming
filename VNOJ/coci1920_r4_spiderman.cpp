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
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int a[MAXN1];
int cnt[MAXN2];
int res[MAXN1];
int g[MAXN2];


signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	for(int i = k + 1; i < MAXN2; ++i) {
		for(int j = i; j < MAXN2; j += i) {
			g[j] += cnt[i];
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		if(a[i] - k < 0) res[i] = 0;
		else if (a[i] - k == 0) res[i] = -1;
		else {
			res[i] = g[a[i] - k];
			if(k == 0) res[i]--;
		}
	}
	
	sort(a + 1, a + n + 1);
	
	int d = 0;
	for(int i = n; i >= 1; --i) {
		if(a[i] == k) break;
		d++;
	}
	
	for(int i = 1; i <= n; ++i) {
		if(res[i] == -1) cout << d << " ";
		else cout << res[i] << " ";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}