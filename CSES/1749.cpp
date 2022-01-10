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

int n;
int st[4*MAXN1];
int a[MAXN1];

void build(int node, int l, int r) {
	if(l == r) {
		st[node] = 1;
		return;
	}
	int mid = (l+r) >> 1;
	build(node << 1, l, mid);
	build(node << 1|1, mid + 1, r);
	st[node] = st[node << 1] + st[node << 1|1];
}


void queryupdate(int node, int l, int r,int pos) {
	if(l == r) {
		st[node] = 0;
		cout << a[l] << " ";
		return;
	}
	int mid = (l+r) >> 1;
	if(pos <= st[node << 1]) queryupdate(node << 1, l, mid, pos);
	else queryupdate(node << 1|1, mid + 1, r, pos - st[node << 1]);
	st[node] = st[node << 1] + st[node << 1|1];
}

signed main() {
	fast_cin();
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	build(1,1,n);
	
	for(int i=1;i<=n;++i) {
		int pos;
		cin >> pos;
		//db(st[1]);
		queryupdate(1,1,n,pos);
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}