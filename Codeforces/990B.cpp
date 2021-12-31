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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n,k;
int a[MAXN1];
bool ok[MAXN2];
int cnt[MAXN2];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i <=n;++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	if(n==1) {
		cout << 1;
		exit(0);
	}
	sort(a+1,a+n+1);
	int ans = 0;
	
	for(int i=2;i<=n;++i) {
		if(a[i] > a[i-1] && a[i] <= a[i-1] + k) ok[a[i-1]] = 1;
		if(ok[a[i-1]])	ans += cnt[a[i-1]];
	}
	cout << n - ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}