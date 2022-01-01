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


int n,a,b,k;
int h[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> a >> b >> k;
	for(int i=1;i<=n;++i) {
		cin >> h[i];
		h[i] %= (a+b);
		if(h[i] == 0) h[i] = a+b;
		h[i] -= a;
		h[i] = max(h[i], 0LL);
	}
	sort(h+1, h+n+1);
	
	int id = 1;
	while(id <= n && k - h[id]/a - (h[id]%a!=0) >= 0) {
		k -= (h[id]/a + (h[id]%a!=0));
		//cout << h[id] << " ";
		id++;
	}
	id--;
	cout << id;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}