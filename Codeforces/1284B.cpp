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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int s[MAXN1],g[MAXN1];
bool check[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	int ans = 0;
	for(int i=1;i<=n;++i) {
		int l;
		cin >> l;
		s[i] = inf;
		g[i] = -inf;
		for(int j=1;j <= l;++j) {
			int x;
			cin >> x;
			if(x > s[i]) check[i] = 1;
			s[i] = min(s[i],x);
			g[i] = max(g[i], x);
		}
	
	}
	vector<int > p,q;
	int cnt = 0;
	for(int i=1;i<=n;++i) {
		if(check[i]) cnt++;
		else {
			p.push_back(s[i]);
			q.push_back(g[i]);
			//ans -= (s[i] < g[i]);
		}
	}
	//cout << ans << "\n";
	ans +=  (2*n -1)*cnt;
	db(ans);
	ans -= (cnt)*(cnt - 1);
	db(ans);

	sort(p.begin(),p.end());
	sort(q.begin(),q.end());
	int id = upper_bound(q.begin(),q.end(), p[0]) - q.begin();	
	for(auto x : p) {
		while(id < sz(q) && q[id] <= x) id++;
		ans += (sz(q) - id);
	}
	cout << ans;
	//cout << max(ans, 0LL);
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}