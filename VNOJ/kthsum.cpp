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

int n,k;
int bit[MAXN1];
int a[MAXN1];

int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos & -pos)) res += bit[pos];
	return res;
}
void update(int pos) {
	for(;pos <= n + 1; pos += (pos & -pos)) bit[pos]++;
}





signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	
	
	int l = -1e14, r = 1e14;
	int ans = 0;
	
	while(l <= r) {
		memset(bit, 0, sizeof bit);
		int mid = (l + r) >> 1;
		vector< pair<pii, int> > f;
		int sum = 0;
		for(int i=0;i<=n;++i) {
			sum += a[i];
			f.push_back({{sum, 1}, i + 1});
			f.push_back({{sum + mid, 0}, i + 1});
		}
		sort(f.begin(), f.end());
		int res = 0;
		for(auto x : f) {
			bool type = x.fi.se;
			int pos = x.se;
			
			if(type) {
				res += get(pos - 1);
/*				db(type);
				db(val);
				db(pos);
				cerr << "\n";*/
			} else{
/*				db(type);
				db(val);
				db(pos);
				cerr << "\n";*/
				update(pos);
			}
		}
		
		if(res >= k) {
/*			db(res);
			cerr << '\n';*/
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	
	
	cout << ans;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}