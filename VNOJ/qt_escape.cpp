/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int MAXN1 = 205;
const int MAXN2 = 1e6+5;
//const int inf = 1e18;

int t;
int m,n;
char a[MAXN1][MAXN1];
bool dist[MAXN1][MAXN1][15];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct state{
	int x,y, poison;
};

signed main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		cin >> m >> n;
		
		// memset
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				for(int k = 0; k <= 9; ++k) {
					dist[i][j][k] = false; 
				}
			}
		}
		
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		
		queue<state> q;
		
		q.push({1, 1, 0});
		dist[1][1][0] = true;
		
		while(!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int poison = q.front().poison;
			
			//db(x);
			//db(y);
			//db(poison);
			//cerr << "\n";
			
			q.pop();
			
			for(int i = 0; i < 4; ++i) {
				int u = x + dx[i];
				int v = y + dy[i];
				
				if(u < 1 || u > m) continue;
				if(v < 1 || v > n) continue;
				if(a[u][v] == '#') continue;
				
				int new_poison = poison;
				
				if(a[u][v] == 'S') new_poison = 0;
				
				else if(a[u][v] != '.') new_poison += (a[u][v] - '0');
				
				if(new_poison < 10 && dist[u][v][new_poison] == false) {
					q.push({u, v, new_poison});
					dist[u][v][new_poison] = true;
				}
				
			}
			
		}
		
		bool can = false;
		for(int p = 0; p < 10; ++p) can |= (dist[m][n][p]);
		
		cout << (can ? "possible\n" : "impossible\n");
		//cerr << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}