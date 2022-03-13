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
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	int low = 0, high = 1e14;
	int res = inf;

	while(low <= high) {
		int mid = (low + high) >> 1;
		int id = 1;
		int cnt = 0, sum = 0;
		int maxx = -1;
		while(id <= n) {
			if(sum + a[id] > mid) {
				cnt++;
				maxx = max(maxx, sum);
				sum = 0;
			}
			sum += a[id];
			if(id == n) {
				cnt++;
				maxx = max(maxx, sum);
			}
			++id;
		}
		if(cnt > k) {
			low = mid + 1;
		} else {
			high = mid - 1;
			if(cnt == k) res = min(res, maxx);
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}