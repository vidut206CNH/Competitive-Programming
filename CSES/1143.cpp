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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
int a[MAXN1];
int st[3*MAXN1];

void build(int node, int l, int r) {
	if(l == r) {
		st[node] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(node << 1, l, mid);
	build(node << 1|1, mid + 1, r);
	st[node] = max(st[node << 1], st[node << 1|1]);
}


void get(int node, int l, int r, int& val) {
	if(l == r) {
		st[node] -= val;
		cout << l << " ";
		return;
	}
	int mid = (l+r) >> 1;
	if(val <= st[node << 1]) get(node << 1, l, mid, val);
	else get(node << 1|1, mid + 1, r, val);
	
	st[node] = max(st[node << 1], st[node <<1|1]);
}

signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	build(1,1,n);
	
	for(int i=1;i<=q;++i) {
		int val;
		cin >> val;
		if(st[1] < val) cout << "0 ";
		else get(1,1,n,val);
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}