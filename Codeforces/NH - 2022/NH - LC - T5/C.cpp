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

int n;
pair<pii,int> a[MAXN1];
int scost[MAXN1], sval[MAXN1];
int fcost[MAXN1], fval[MAXN1];
int f[MAXN1], s[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	set<int> st;
	
	for(int i = 1; i <= n; ++i) {
		int p,d,w;
		cin >> p >> w >> d;
		a[i].fi.fi = p - d;
		a[i].fi.se = p + d;
		a[i].se = w;
		st.insert(a[i].fi.fi);
		st.insert(a[i].fi.se);
	}
	
	sort(a + 1, a + n + 1);
	sval[n] = a[n].se;
	s[n] = a[n].fi.fi;
	for(int i = n - 1;i >= 1; --i) {
		s[i] = a[i].fi.fi;
		sval[i] = sval[i + 1];
		scost[i] = scost[i + 1] + sval[i]*(a[i + 1].fi.fi - a[i].fi.fi);
		sval[i] += a[i].se;
	}
	
	sort(a + 1, a + n + 1, [&](const pair<pii, int> &A, const pair<pii, int> &B){
		return A.fi.se < B.fi.se;
	});
	
	fval[1] = a[1].se;
	f[1] = a[1].fi.se;
	
	for(int i = 2; i <= n; ++i) {
		f[i] = a[i].fi.se;	
		fval[i] = fval[i - 1];
		fcost[i] = fcost[i - 1] + fval[i]*(a[i].fi.se - a[i - 1].fi.se);
		fval[i] += a[i].se;
		
	}
	int res = 1e18 + 5;
	
	for(auto x : st) {
		int sum = 0;
		int pos1 = lower_bound(s + 1, s + n + 1, x) - s;
		
		sum = sum + scost[pos1] + sval[pos1]*(s[pos1] - x);
		
		int pos2 = lower_bound(f + 1, f + n + 1, x) - f;
		--pos2;
		
		sum = sum + fcost[pos2] + fval[pos2]*(x - f[pos2]);
		res = min(res, sum);
	}
	
	cout << res;
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}