// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
using namespace std;

typedef pair<int,int> pii;

const int mxn = 1e6+5;
const int mod = 1e9+7;
const int inf = 2e18;
const int base =1e5;
const double eps = 1e-9;

bool p[mxn];
int a[100005],f[100005];
int ind[200005];

vector<int> st[4*base];


void sieve() {
	p[0] = 1;
	p[1] = 1;
	for(int i=2;i*i <= (int)1e6;++i) {
		if(p[i]) continue;
		for(int j=i*i;j<=(int)1e6;j += i) p[j] = 1; 
	}
}

void build(int id, int l,int r) {
	if(l == r) {
		st[id] = {f[l]};
		return;
	}
	int mid = (l+r)/2;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	st[id].resize(r - l + 1);
	merge(st[id << 1].begin(),st[id << 1].end(),st[id << 1| 1].begin(),st[id << 1|1].end(),st[id].begin());
}

int get(int id,int l,int r,int u,int v,int val) {
	if(r < u || v < l) return 0;
	if(u <= l && r <= v) {
		int k = upper_bound(st[id].begin(), st[id].end(), val) - st[id].begin();
		return k;
	}
	int mid = (l+r)>>1;
	return get(id << 1, l, mid,u,v,val) + get(id << 1|1, mid + 1, r, u, v, val);
}

signed main() {
	fast_cin();
	sieve();
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		if(p[x]) a[i] = - 1;
		else a[i] = 1;
		f[i] = f[i-1] + a[i];
	}
	build(1,0,n);
	//cout << get(1,0,n,0,n-1,f[n]);
	int ans = 0;
	for(int i=1;i<=n;++i) {
		ans += get(1,0,n,0,i-1, f[i]);
		//cout << ans << "\n";
	}
	cout << ans;
	

}