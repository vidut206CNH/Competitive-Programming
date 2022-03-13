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
const int MAXN2 = (1 << 20) + 5;
const int inf = 1e18;

int n;
int a[MAXN1];
map<vector<int>, int> mp[2];

vector<int> f(int x) {
	vector<int> res(20);
	for(int i = 19; i >= 0; --i ){
		res[i] = (x >> i & 1);	
	}
	
	return res;
}

void comb(vector<int> &res, vector<int> g) {
	for(int i = 0; i < 20; ++i) {
		res[i] = (res[i] + g[i])%2;
	}
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	vector<int> d(20, 0);
	mp[0][d] = 1;
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		vector<int> tmp = f(a[i]);
		comb(d, tmp);
		res += mp[i&1][d];
		mp[i&1][d]++;
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}