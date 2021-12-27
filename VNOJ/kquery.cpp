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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 3e4+5;


struct data{
	int t,l,r,val,id;
	
	bool operator() (data &A, data &B) {
		if(A.val == B.val) return A.t > B.t;
		return A.val > B.val;
	}
};


int n,q;
data a[MAXN1 + MAXN2];
int bit[MAXN2];
int res[MAXN1];

void update(int pos) {
	for(;pos <= n; pos += pos&-pos) bit[pos]++;
}

int get(int pos) {
	int ans = 0;
	for(;pos > 0;pos -= pos&-pos) ans += bit[pos];
	return ans;
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i].val;
		a[i].l = i;
		a[i].r = i;
		a[i].id = i;
		a[i].t = 0;
	}
	cin >> q;
	for(int i=1;i<=q;++i) {
		cin >> a[i+n].l >> a[i+n].r >> a[i+n].val;
		a[i+n].t = 1;
		a[i+n].id = i;
	}
	
	sort(a + 1, a + n + q + 1, data());
	
	for(int i=1;i<=n+q;i++) {	
		
		if(a[i].t) {
			res[a[i].id] = get(a[i].r) - get(a[i].l - 1);
		} else {
			update(a[i].l);
		}
		
	}
	
	for(int i=1;i<=q;++i) cout << res[i] << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}