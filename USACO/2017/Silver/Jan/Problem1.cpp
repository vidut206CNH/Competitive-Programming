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
const int MAXN1 = 1e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,lim;
int a[MAXN1];

signed main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	fast_cin();
	
	cin >> n >> lim;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	int l=1,r = n,res = 0;
	while(l <= r) {
		int mid = (l+r) >> 1;
		priority_queue<int, vector<int>, greater<int> > p; 
		for(int i=1;i<=mid;++i) {
			p.push(a[i]);
		}
		int id = mid,maxx = 0;
		while(!p.empty()) {
			int d = p.top();
			p.pop();
			maxx = d;
			if(id < n) p.push(a[++id] + d);
		}
		
		if(maxx <= lim) {
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}