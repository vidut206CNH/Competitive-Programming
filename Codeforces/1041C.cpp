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

int n,m,d;


signed main() {
	fast_cin();
	
	cin >> n >> m >> d;
	priority_queue<pii, vector<pii >, greater<pii > > p;
	
	vector<int> res(n + 5);
	vector<int> minn(n + 5);
	vector<pii > a(n + 5);
	
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	
	sort(a.begin() + 1, a.begin() + n + 1);
	
	int g = 0;
		
		
		
	for(int i = 1; i <= n; ++i) {
		int val = a[i].fi;
		int pos = a[i].se;
		if(!p.empty() && val - p.top().fi > d) {

			pii pre = p.top();
			res[pos] = res[pre.se];
			p.pop();
			p.push({val, pos});
		}
		else {
			res[pos] = ++g;
			p.push({val, pos});
		}
	}
	
	cout << g << "\n";
	for(int i = 1; i <= n; ++i) cout << res[i] << " ";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}