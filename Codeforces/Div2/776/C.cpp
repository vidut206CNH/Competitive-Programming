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

int t;

pair<int,pii > a[MAXN1];
int L[MAXN1];
int R[MAXN1];


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		for(int i = 1; i <= m; ++i) {
			cin >> a[i].se.fi >> a[i].se.se;
			a[i].fi = i;
		}
		
		sort(a + 1, a + m + 1, [&](const pair<int, pii > &A, const pair<int, pii > &B) {
			return A.se.fi < B.se.fi;
		});
		priority_queue<int> p;
		
		
		int sum = 0;
		for(int i = 1; i <= n; ++i) {
			sum += a[i].se.se;
			p.push(a[i].se.se);
			if(i == n) L[i] = sum;
		}
		
		for(int i = n + 1; i <= m - n; ++i) {
			sum += a[i].se.se;
			p.push(a[i].se.se);
			sum -= p.top();
			p.pop();
			L[i] = sum;
		}
		
		while(!p.empty()) p.pop();
		
		
		sum = 0;
		for(int i = m; i >= m - n + 1; --i) {
			sum += a[i].se.se;
			p.push(a[i].se.se);
			if(i == m - n + 1) R[i] = sum;
		}
		
		for(int i = m - n; i > n; --i) {
			sum += a[i].se.se;
			p.push(a[i].se.se);
			sum -= p.top();
			p.pop();
			R[i] = sum;
		}
		int best = inf, id = 0;
		for(int i = n; i <= m - n; ++i) {
			if(best > L[i] + R[i + 1]) {
				best = L[i] + R[i + 1];
				id = i;
			}
		}
		
		priority_queue<pair<int, pii > > pq;
		vector<pii> res;
		for(int i = 1; i <= id; ++i) {
			pq.push({a[i].se.se, {a[i].se.fi, a[i].fi}});
			if(i > n) pq.pop();
		}
		
		while(!pq.empty()) {
			res.push_back(pq.top().se);
			pq.pop();
		}
		
		
		for(int i = m; i > id; --i) {
			pq.push({a[i].se.se, {a[i].se.fi, a[i].fi}});
			if(i < m - n + 1) pq.pop();
		}
		
		while(!pq.empty()) {
			res.push_back(pq.top().se);
			pq.pop();
		}
		
		sort(res.begin(), res.end());
		
		
		cout << best << "\n";
		int l = 0, r = sz(res) - 1;
		while(l < r) {
			cout << res[l].se << " " << res[r].se << "\n";
			++l;
			--r;
		}
		cout << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}