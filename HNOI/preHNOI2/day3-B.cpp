/* 
	link problem: 
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
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 2e5 + 5;


int a[MAXN2];
pii q[MAXN2];

int st[MAXN2];

void build(int id, int l,int r) {
	if(l == r) {
		st[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(id << 1, l, mid);
	build((id << 1)|1, mid + 1, r);
	st[id] = max(st[id << 1], st[(id << 1)|1]);
}

int get(int id, int l,int r,int &u,int &v) {
	if(v < l || r < u) return -INF;
	if(u <= l && r <= v) return st[id];
	int mid = (l+r)/2;
	return max(get(id << 1, l, mid, u, v), get((id << 1)|1, mid + 1, r, u, v));
}


signed main() {
	fast_cin();
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	a[0] = a[1];
	for(int i=1;i<=m;++i) cin >> q[i].fi >> q[i].se;
	int res = 0,index=1;
	for(int id=1;id<=n;++id) {
		
		swap(a[id],a[id-1]);
		build(1,1,n);
		vector<pii> cur(n+1);
		cur[0] = {0,0};
		for(int i=1;i <= n;++i) cur[i] = {i,i};
		int ans = 0;
		for(int i=1;i<=m;++i) {
			int l = q[i].fi;
			int r = q[i].se;
			int maxx = get(1,1,n,cur[l].fi, cur[r].se);
			cur[l].se = cur[r].se;
			
			//cout << cur[l].fi << " " << cur[l].se << "\n";
			
			if(l <= id) {
				if(a[id] != maxx) break;
				ans++;
			}
			cur.erase(cur.begin() + l, cur.begin() + r);
			if(m - i <= res) break;
			//cout << cur[l].fi << " " << cur[l].se << "\n";
		}
		if(ans > res) {
			res = ans;
			index = id;
		}
		//cout << ans << "\n";
	}
	cout << res << " " << index;
	
	return 0;
}