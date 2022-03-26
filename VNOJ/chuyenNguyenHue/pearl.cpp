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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int cnt[MAXN1];


int solve(int val) {
	int res = 1e9 + 7;
	
	for(int i = 1; i <= n/val; ++i) {
		int sum = 0;	
		for(int pos = val*(i - 1) + 1; pos <= val*i; ++pos) {
			cnt[a[pos]]++;
			if(cnt[a[pos]] == 1) sum++;
		}
		
		for(int pos = val*(i - 1) + 1; pos <= val*i; ++pos) {
			cnt[a[pos]]--;
		}
		
		
		res = min(res, sum);
	}
	
	return res;
}

signed main() {
	fast_cin();
	
	
	cin >> n;
	map<int, int> mp;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]] = 1;
	}
	int id = 0;
	for(auto &x : mp) {
		x.se = id;
		++id;
	}
	
	
	for(int i = 1; i <= n; ++i) {
		a[i] = mp[a[i]];
	}
	
	

	
	vector<pii > res;
	for(int d = 1; d *d <= n; ++d) {
		if(n%d) continue;
		
		res.push_back({d, solve(d)});
		if(d*d != n) res.push_back({n/d, solve(n/d)});
	}
	
	sort(res.begin(),res.end());
	cout << sz(res) << "\n";
	for(auto x : res) {
		cout << x.fi << " " << x.se << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}