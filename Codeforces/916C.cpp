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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 1e6+5;
const int inf = 1e9;

int n,m;
int p[MAXN1];
vector<pii > E[MAXN1];

signed main() {
	fast_cin();
	cin >> n >> m;
	p[1] = 1;
	for(int i=2;i*i<MAXN1;++i) {
		if(!p[i]) for(int j=i*i;j <MAXN1;j += i) p[j] = 1;
	}
	int wei;
	for(int i=n-1;i < MAXN1;++i) {
		if(!p[i]) {
			wei = i;
			break;
		}
	}
	
	for(int i=1;i<n;++i) {
		if(i != n - 1) E[i].push_back({i+1,1});
		else E[i].push_back({i+1, wei - (n - 2)});
		--m;
	}
	
	for(int i=1;i < n; ++i) {
		for(int j=i + 2;j <= n; ++ j) {
			if(!m) break;
			E[i].push_back({j, inf});
			--m;
		}
	}
	
	cout << wei << " " << wei << "\n";
	for(int i=1;i <= n;++i) {
		for(auto x : E[i]) cout << i << " " << x.fi <<  " " << x.se << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}