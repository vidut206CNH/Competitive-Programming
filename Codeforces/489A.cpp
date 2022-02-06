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
const int MAXN1 = 3005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	vector<pii > res;
	for(int pos = 0; pos < n; ++pos) {
		int minn = a[pos],id = pos;
		for(int j = pos + 1; j < n; ++j) {
			if(a[j] < minn) {
				minn = a[j];
				id = j;
			}
		}
		if(id != pos) res.push_back({pos, id});
		swap(a[pos], a[id]);
	}
	
	cout << sz(res) << "\n";
	for(auto x : res) cout << x.fi << " " << x.se << "\n";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}