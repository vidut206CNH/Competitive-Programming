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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;



int n;
pii a[MAXN1];
vector<pii> p;

int find_worst(int id) {
	
	vector<int> cur = {a[id].fi, a[id].se, n};
	
	
	int low = 1, high = n, res = -1;
	while(low <= high) {
		int mid = (low + high) >> 1;
		
		
	}
	
	
}



int find_best(int id) {
	
}


signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;		
	}
	
	for(int i = 1; i <= n; ++i) {
		p.clear();
		for(int k = 1; k <= n; ++k) {
			if(i == k) continue;
			p.push_back(a[i]);
		}
		
		sort(p.begin(), p.end(), [&](const pii& A, const pii& B) {
			if(max(A.fi, A.se) != max(B.fi, B.se)) return max(A.fi, A.se) < max(B.fi, B.se);
			return min(A.fi, A.se) < min(B.fi, B.se);
		});
		
		int res1 = find_worst(i);
		int res2 = find_best(i);
		
		cout << res2 << " " << res1 << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}