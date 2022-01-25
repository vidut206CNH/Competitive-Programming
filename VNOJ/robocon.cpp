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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
bool a[MAXN1][MAXN1];

bool mark[2][MAXN1][MAXN1];
queue<pii > q[2];

vector< vector<int> > dx = {{0, 1, 1}, {0, 1, 1}};
vector< vector<int> > dy = {{1, 1, 0}, {-1, -1, 0}};


signed main() {
	fast_cin();
	
	
	cin >> n >> k;
	
	for(int i=1;i<=k;++i) {
		int u,v;
		cin >> u >> v;
		a[u][v] = true;
	}
	
	bool dir = 0;
	int res = 0;
	
	q[0].push({1,1});
	mark[0][1][1] = true;
	q[1].push({1,n});
	mark[1][1][n] = true;	
	
	
	while(true) {
		
		if(dir) res++;
		
		int _size = sz(q[dir]);
		while(_size--) {
			pii cur = q[dir].front();
			
			q[dir].pop();
			
			mark[dir][cur.fi][cur.se] = false;
			
			for(int i=0;i<3;++i) {
				int u = cur.fi + dx[dir][i];
				int v = cur.se + dy[dir][i];
				
				if(u < 1 || u > n) continue;
				if(v < 1 || v > n) continue;
				if(a[u][v]) continue;
				
				if(dir && mark[!dir][u][v]) {
					cout << res;
					exit(0);
				}
				
				q[dir].push({u,v});
				
			}
		}
		
		_size = sz(q[dir]);
		
		while(_size--) {
			pii cur = q[dir].front();
			
			q[dir].pop();
			
			if(mark[dir][cur.fi][cur.se] == false) {
				mark[dir][cur.fi][cur.se] = true;
				q[dir].push(cur);
			}
		}
		
		dir ^= 1;
		
	}
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}