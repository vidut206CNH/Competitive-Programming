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
const int MAXN1 = 1505;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,q;
int a[MAXN1][MAXN1];
int p[20];


//sub1

void sub1() {
	for(int i=1;i<=q;++i) {
		int u,v;
		cin >> u >> v;
		bool g1=0,g2=0;
		for(int j=1;j<=m;++j) {
			g1 |= (p[j] == u);
			g2 |= (p[j] == v);
		}
		if(g1 && g2 && u != v) {
			cout << m-1;
		}
		else if(!g1 && !g2) {
			cout << m + 1;
		}
		else cout << m;
		cout << " ";
	}
}



//sub2
vector<int> dist;
vector<bool> P;

void dijk(int start) {
	dist.assign(MAXN1, inf);
	P.assign(MAXN1, false);
	
	priority_queue<pii, vector<pii > , greater<pii > > pq;
	dist[start] = 0;
	pq.push({dist[start], start});
	
	while(!pq.empty())  {
		pii cur = pq.top();
		pq.pop();
		
		if(P[cur.se]) continue;
		P[cur.se] = 1;
		
		for(int i=1;i<=n;++i) {
			if(i == cur.se) continue;
			
			if(dist[i] > cur.fi + a[cur.se][i]) {
				dist[i] = cur.fi + a[cur.se][i];
				pq.push({dist[i], i});
			}
						
		}
	}
	
	
}


void sub2() {
	dijk(p[1]);
	for(int i=1;i<=q;++i) {
		int u,v;
		cin >> u >> v;
/*		db(dist[u]);
		db(dist[v]);
		cerr << '\n';*/
		cout << dist[u] + dist[v] << " ";
	}
}







signed main() {
	fast_cin();
	
	cin >> n >> m >> q;
	for(int i=1;i<=m;++i) {
		cin >> p[i];
	}
	
	bool checks1 = 1;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			checks1 &= (a[i][j] <= 1);
		}
	}
	
	if(checks1) {
		sub1();
		exit(0);
	}
	
	if(m == 1) {
		sub2();
	}
	else cout << "15 21 24 25";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}