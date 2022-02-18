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


int n;


signed main() {
	fast_cin();
	
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	
	cin >> n;
	vector<pii > p(n + 5);
	unordered_map<int, vector<int> > row, col;
	
	for(int i = 1; i <= n + 2; ++i) {
		cin >> p[i].fi >> p[i].se;
		row[p[i].fi].push_back(i);
		col[p[i].se].push_back(i);
	}	
	
	vector<int> dist(n + 5, inf);
	
	
	queue<pair<int, bool> > q;
	// < index, dir >
	
	q.push({1, false});
	q.push({1, true});
	dist[1] = 0;
	
	while(!q.empty()) {
		
		bool dir = q.front().se;
		// false - horizontal
		// true - vertical
		
		int g = q.front().fi;
		

		
		q.pop();
		
		if(dir == false) {
			
			int r = p[g].fi;
			
			for(auto id : row[r]) {
				if(dist[id] == inf) {
					dist[id] = dist[g] + 1;
					q.push({id, !dir});
				}
			}		
		} else {
			int c = p[g].se;
			
			for(auto id : col[c]) {
				if(dist[id] == inf) {
					dist[id] = dist[g] + 1;
					q.push({id, !dir});
				}
			}
		}
	}
	
	
	if(dist[2] == inf) cout << -1;
	else cout << dist[2] - 1;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}