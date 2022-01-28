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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,t;
int delta[MAXN1];
int sum[MAXN1];
int cnt[MAXN2];
pii query[MAXN1];
int a[MAXN1];

pii get(int pos) {
	pii res;
	for(;pos > 0; pos -= (pos & -pos)) {
		res.fi += delta[pos];
		res.se += sum[pos];
	}
	return res;
}

void update(int pos, int val) {
	cnt[val]++;
	for(;pos <= n; pos += (pos & -pos)) {
		delta[pos] += (2 * cnt[val])*val;
		sum[pos] += (2*(cnt[val] - 1)*val + val);
	}
	db(2*(cnt[val] - 1)*val + val);
	cerr << "\n";
}

signed main() {
	fast_cin();
	
	cin >> n >> t;
	
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	for(int i=1;i<=t;++i) {
		cin >> query[i].fi >> query[i].se;
	}
	
	sort(query + 1, query + t + 1, [&] (const pii& A, const pii& B) {
		return A.se < B.se;
	});
	int id = 1;
	for(int i = 1; i <= n;++i) {
		update(i, a[i]);
		while(id <= t && i == query[id].se) {
			db(i);
			int l = query[id].fi;
			int r = query[id].se;
			pii left = get(l - 1);
			pii right = get(r);
			db(right.se);
			db(left.se);
			cerr << "\n";
			int ans = right.se - left.se - left.fi;
			
			cout << ans << "\n";
			++id;
		} 
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}