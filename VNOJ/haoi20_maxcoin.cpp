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

int n,m;


signed main() {
	fast_cin();
	
	cin >> n >> m;
	vector<pii> p;
	for(int i = 1; i <= m; ++i) {
		int L,R;
		cin >> L >> R;
		if(L <= R) {
			p.push_back({L, 0});
			p.push_back({R, 1});
		}
		
		else {
			p.push_back({1, 0});
			p.push_back({R, 1});
			p.push_back({L, 0});
			p.push_back({n, 1});
		}
	}	
	
	sort(p.begin(), p.end());
	int res1 = 0, res2 = 0, cnt = 0;
	for(int i = 0; i < sz(p); ++i) {
		if(p[i].se == 0) {
			cnt++;
			if(cnt > res1) {
				res1 = cnt;
				res2 = p[i + 1].fi - p[i].fi + 1;
			}
			
			else if(cnt == res1) {
				res2 += p[i + 1].fi - p[i].fi + 1;
			}
		}
		
		else cnt--;
	}
	
	cout << res1 << " " << res2;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}