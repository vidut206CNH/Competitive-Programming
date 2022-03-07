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
const int MAXN1 = 255;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,A,B;
vector<int>  adj[MAXN1];
queue<int> q[2];

bool inQueue[2][MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> m >> A >> B;
	if(A == B) {
		cout << 0;
		exit(0);
	}
	
	for(int i = 1; i <= m; ++i) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	
	// BFS
	bool state = 0;
	q[state].push(A);
	q[!state].push(B);
	
	stack<int> st;
	int res = 0;
	
	while(true) {
		++res;
		
		
		// from A
		while(!q[state].empty()) {
			int cur = q[state].front();
			q[state].pop();
			st.push(cur);
			inQueue[state][cur] = false; 
		}
		
		while(!st.empty()) {
			int cur = st.top();
			st.pop();
			for(auto next : adj[cur]) {
				if(inQueue[state][next]) continue;
				inQueue[state][next] = true;
				q[state].push(next);
			}
		}
		
		
		
		
		// from B
		
		state ^= 1;
		
		
		while(!q[state].empty()) {
			int cur = q[state].front();
			q[state].pop();
			st.push(cur);
			inQueue[state][cur] = false; 
		}
		
		while(!st.empty()) {
			int cur = st.top();
			st.pop();
			for(auto next : adj[cur]) {
				if(inQueue[state][next]) continue;
				
				if(inQueue[!state][next]) {
					cout << res;
					exit(0);
				}
				
				inQueue[state][next] = true;
				q[state].push(next);
			}
		}		
		
		
		
		state ^= 1;
		
	}
	
	assert(false);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}