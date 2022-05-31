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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;

int n,m;
vector<pii> p;
bool ok[MAXN1];

int main() {
	fast_cin();
	
	cin >> n >> m;
	
	if(m == 1) {
		cout << "YES\n";
		exit(0);
	}
	vector<int> node(4, 0);	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		if(node[0] == 0 && node[1] == 0) {
			node[0] = u;
			node[1] = v;
		}
		
		else if (node[0] != u && node[1] != u && node[0] != v && node[1] != v) {
			node[2] = u;
			node[3] = v;
		}
		
		p.push_back({u,v});
		
	}
	
	if(node[3] == 0) {
		cout << "YES\n";
		exit(0);
	}
	bool good = false;
	
	for(int i = 0; i < 4; ++i) {
		for(int j = i + 1; j < 4; ++j) {
			
			if(node[i] == node[j]) continue;
			
			int cnt = 0;
			for(auto x : p) {
				cnt += (x.fi == node[i] || x.fi == node[j] || x.se == node[i] || x.se == node[j]);
			}
			
			good |= (cnt == m);
		}
	}
	
	
	cout << (good ? "YES\n" : "NO\n");
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}