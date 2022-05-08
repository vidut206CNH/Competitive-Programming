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

int t;
int n;
int a[MAXN1];
int b[MAXN1];
int fix[MAXN1];
bool visited[MAXN1];
vector<int> adj[MAXN1];
int res = 0;


int power(int A, int B) {
	int C = 1; 
	while(B) {
		if(B&1) C = C*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return C;
}

void dfs(int u, int root) {
	visited[u] = true;
	
	for(auto v : adj[u]) {
		
		if(v == root) {
			res++;
			return;
		}
		
		dfs(v, root);	
	}
}



signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		
		res = 0;
		
		for(int i = 1; i <= n; ++i) {
			fix[i] = 0;
			adj[i].clear();
			visited[i] = false;		
		}
		
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) cin >> b[i];
		
		for(int i = 1; i <= n; ++i) {
			cin >> fix[i];
		}
		
		for(int i = 1; i <= n; ++i) {
			
			if(a[i] != b[i] && fix[i] == 0) {
				
				adj[a[i]].push_back(b[i]);
				
			}
			
		}
		
		for(int i = 1; i <= n; ++i) {
			if(visited[i] == false) {	
				dfs(i, i);
			}
		}
		
		cout << power(2, res) << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}