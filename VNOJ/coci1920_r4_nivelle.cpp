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

int a[MAXN1];
int cnt[35];
int n;

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		a[i] = c - 'a';
	}
	pair<int,int> best, res = {1, 1};
	best = {1, 1};
	for(int i = 1; i <= 26; ++i) {
		int l = 1, r = 1;
		memset(cnt, 0, sizeof cnt);
		int d = 0;
		while(r <= n) {
/*			db(l);
			db(r);
			cerr << "\n";*/
			cnt[a[r]]++;
			if(cnt[a[r]] == 1) d++;
			while(d > i) {
				cnt[a[l]]--;
				if(cnt[a[l]] == 0) --d;
				++l;
			}
			if(best.fi*(r - l + 1) > best.se*d) {
				best.fi = d;
				best.se = (r - l + 1);
				res.fi = l;
				res.se = r;
			}
			++r;
		}
	}
	
	cout << res.fi << " " << res.se;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}