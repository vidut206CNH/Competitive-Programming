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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;
vector<int> adj[MAXN1];
char s[MAXN1];
bool visited[MAXN1];
int cnt[30];
int num = 0;

void dfs(int u) {
	visited[u] = true;
	num++;
	cnt[s[u] - 'a' + 1]++;
	for(auto x : adj[u]) {
		if(visited[x] == true) continue;
		dfs(x);
	}
}


signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			cin >> s[i];
			adj[i].push_back(n - i + 1);
			if(i  <= n - k) adj[i].push_back(i + k);
			if(i > k ) adj[i].push_back(i - k);
		}
		int res = 0;
		
		for(int i = 1; i <= n; ++i) {
			if(visited[i] == false) {
				num = 0;
				memset(cnt, 0, sizeof cnt);
				
				dfs(i);
				
				int best = num;		
				for(int id = 1; id <= 26; ++id) {
					best = min(best, num - cnt[id]);
				}
				
				res += best;
				
			}
		}
		
		for(int i = 1; i <= n; ++i) adj[i].clear();
		for(int i = 1; i <= n; ++i) visited[i] = false;
		
		cout << res << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}