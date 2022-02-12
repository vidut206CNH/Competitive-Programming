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
const int MAXN1 = 5e4 + 5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

pii a[MAXN1];
int m,n;

vector<int> d[MAXN1];

signed main() {
	fast_cin();
	
/*	freopen("QUEUE.INP", "r", stdin);
	freopen("QUEUE.OUT", "w", stdout);*/
	
	int t;
	cin >> t;
	
	
	
	while(t--) {
		
		cin >> m >> n;
		for(int i=1;i <= n; ++i) {
			cin >> a[i].fi >> a[i].se;
		}
		
		int low = 1, high = n, res = 0;
		
		while(low <= high) {
			
			int mid = (low + high) >> 1;
			
			for(int i=1;i<=mid; ++i) {
				int l = a[i].fi;
				int r = a[i].se;
				d[l].push_back(r);
			}
			
			bool bad = false;
			
			priority_queue<int, vector<int>, greater<int> > pq;
			
			
			for(int pos = 1; pos <= m; ++pos) {
				if(!pq.empty() && pq.top() < pos) {
					bad = true;
					break;
				}
				
				for(auto x : d[pos]) {
					pq.push(x);
				}
				
				if(!pq.empty()) {
					pq.pop();
				}
				
			}
			
			if(!pq.empty()) {
				bad = true;
			}
			
			for(int i = 1; i <= m; ++i) {
				d[i].clear();
			}
			
			if(bad) {
				high = mid - 1;
			} else {
				res = mid;
				low = mid + 1;
			}
			
			
		}
		
		cout << res << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
