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
#define INF 1e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const double eps = 1e-10;


struct node{
	int u,w;
	bool operator() (node &A, node&B) {
		return A.w > B.w;
	}
};

vector<pii > E[MAXN1];
vector<int> dist1(MAXN1,INF);
vector<int> distn(MAXN1,INF);
vector<int> P;
pii f_a[MAXN1];
pii f_b[MAXN1];
int mina[MAXN1];
int minb[MAXN1];


void dijk(vector<int>& dist, int start) {
	P.assign(MAXN1, 0);
	priority_queue<node, vector<node>, node> p;
	dist[start] = 0;
	p.push({start,dist[start]});
	
	while(!p.empty()) {
		node cur = p.top();
		p.pop();
		
		if(P[cur.u]) continue;
		
		P[cur.u] = 1;
		
		for(auto edge : E[cur.u]) {
			if(dist[edge.fi] > cur.w + edge.se) {
				
				dist[edge.fi] = cur.w + edge.se;
				
				p.push({edge.fi, dist[edge.fi]});
				
			}
		}
	}
	
}

int n,m,k;


bool comp(const pii& A, const pii& B) {
	return (1.0*B.fi/B.se - 1.0*A.fi/A.se > eps);
}



int bs(pii A[], int a,int b) {
	int l=2,r = n - 1,ans = n,mid;
	
	while(l <= r) {
		mid = (l+r) >> 1;
		if(A[mid].fi*b >= A[mid].se * a) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}


signed main() {
	fast_cin();
	cin >> n >> m >> k;
	for(int i=1;i<=m;++i) {
		int u,v,w;
		cin >> u >> v >> w;
		E[u].push_back({v,w});
		E[v].push_back({u,w});
	}
	dijk(dist1,1);
	dijk(distn,n);
	
	for(int i=2;i<=n-1;++i) {
		f_a[i] = {dist1[i], distn[i]};
		f_b[i] = {distn[i], dist1[i]};
		//cout << f_a[i].fi << " " << f_a[i].se << "\n";
	}
	sort(f_a+2, f_a + n, comp);
	sort(f_b+2, f_b + n, comp);
	mina[n] = INF;
	minb[n] = INF;
	for(int i=n-1;i>1;--i) {
		mina[i] = min(mina[i + 1], f_a[i].fi);
		minb[i] = min(minb[i + 1], f_b[i].fi);
		//cout << mina[i] << " " << 
	}
	
	for(int i=1;i<=k;++i) {
		int a,b;
		cin >> a >> b;
		int res = INF;
		int t1 = bs(f_a, b, a);
		if(t1 != n) res = min(res, 1LL*mina[t1]*a);
		//cout << f_a[t1].fi << " " << f_a[t1].se << "\n";
		int t2 = bs(f_b, a, b);
		if(t2 != n) res = min(res, 1LL*minb[t2]*b);
		//cout << f_b[t2].se << " " << f_b[t2].fi << "\n";
		res = min(res, 1LL*b*distn[1]);
		res = min(res, 1LL*a*dist1[n]);
		cout << res << "\n";
	}
	
	
	
	return 0;
}
