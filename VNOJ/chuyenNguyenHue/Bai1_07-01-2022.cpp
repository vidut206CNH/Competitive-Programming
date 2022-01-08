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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,k;
int mark[MAXN1];
int b[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> m >> k;
	int cnt = 0;
	vector<int> p,d;
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		if(!mark[x]) cnt++;
		if(mark[x]) p.push_back(x);
		mark[x]++;
	}
	for(int i=1;i <= m;++i) {
		if(!mark[i]) d.push_back(i);
	}
	
	if(sz(d) + cnt < k) {
		cout << -1;
		exit(0);
	}
	else {
		sort(d.begin().d.end());
		
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}