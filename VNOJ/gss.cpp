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
const int MAXN1 = 5e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

struct node{
	int l;
	int r;
	int sum;
	int best;
	node operator+(const node& B) const {
		node res;
		res.best = max(max(best, B.best), r + B.l);
		res.l = max(l, sum + B.l);
		res.r = max(r + B.sum, B.r);
		res.sum = sum + B.sum;
		return res;
	}
};

int n;
node st[3*MAXN1];
int a[MAXN1];

void build(int id, int l, int r) {
	if(l==r) {
		st[id] = {a[l],a[l], a[l], a[l]};
		return;
	}
	int mid = (l+r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[id] = st[id  << 1] + st[id << 1|1];
}

void get(int id, int l,int r, int& u, int&v, node& res) {
	if(u <= l && r <= v) {
		res = res + st[id];
		return;
	}
	int mid = (l+r) >> 1;
	if(u <= mid) get(id << 1, l, mid, u ,v, res);
	if(mid +1 <= v) get(id << 1|1, mid + 1, r, u, v, res);
}

signed main() {
	fast_cin();
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	build(1,1,n);
	
	int q;
	cin >> q;
	for(int i=1;i<=q;++i) {
		int u,v;
		cin >> u >> v;
		node res = {-inf,-inf,0LL,-inf};
		get(1,1,n,u,v,res);
		cout << res.best << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}