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


int n,k;
int a[MAXN1];
int color[MAXN1];
vector<int> adj[MAXN1];
bool visited[MAXN1];
int cnt_0, cnt_1;

void dfs(int u, int c) {
	if(c == 0) cnt_0++;
	else cnt_1++;
	for(auto v : adj[u]) {
		if(visited[v] == false) {
			visited[v] = true;
			dfs(v, !c);
		}
	}
}


signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	if(k == 1) {
		sort(a + 1, a + n + 1);
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			res += (i == 1 || a[i] != a[i - 1]);
		}
		
		cout << res;
		exit(0);
	}
	
	sort(a + 1, a + n + 1);
	int r = 1;
	
	for(int i = 1; i <= n; ++i) {
		while(r <= n && a[i]*k > a[r]) {
			++r;
		}
		
		if(r <= n && a[i]*k == a[r]) {
			adj[i].push_back(r);
			adj[r].push_back(i);
		}
	}
	int res = 0;
	
	for(int i = 1; i <= n; ++i) {
		
		if(visited[i] == false) {
			
			cnt_0 = 0;
			cnt_1 = 0;
			visited[i] = true;
			dfs(i, 0);
			res += max(cnt_0, cnt_1);
			
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}