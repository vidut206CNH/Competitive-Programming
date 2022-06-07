/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;

int n,q,m;
vector<int> adj[MAXN1];
int h[MAXN1];

int main() {
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cin >> q;
	while(q--) {
		int x,d;
		cin >> x >> d;
		++d;
		vector<int> res;
		queue<int> qu;
		h[x] = 1;
		qu.push(x);
		
		while(!qu.empty()) {
			int u = qu.front();
			res.push_back(u);
			qu.pop();
			
			for(auto v : adj[u]) {
				if(h[v] == 0 && h[u] < d) {
					h[v] = h[u] + 1;
					qu.push(v);
				}
			}
		}
		
		long long sum = 0;
		for(auto val : res) {
			sum += val;
			h[val] = 0;
		}
		
		cout << sum << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}