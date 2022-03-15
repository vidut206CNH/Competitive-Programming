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
const int MAXN2 = 1e7+5;
const int inf = 1e18;

int n,m,k;
int cnta[MAXN2];
int cntb[MAXN2];
int f[MAXN2];

signed main() {
	fast_cin();
	
	
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i) cin >> b[i];
	sort(b.begin(), b.end(), greater<int>());
	
	for(int i = 0; i < n; ++i) {
		cnta[a[i]]++;
	}
	
	int lim = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));
	
	int low = 0, high = m;
	int res = -1;
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		
		for(int i = 0; i < mid; ++i) {
			cntb[b[i]]++;
		}
		
		bool can = true;
		for(int val = 0; val <= lim; ++val) {
			f[val] = cntb[val] + cnta[val];
			if(val > 0) f[val] += f[val - 1];
			if(f[val] > k*(val + 1)) {
				can = false;
				break;			
			}
		}
/*		db(mid);
		db(can);*/
		
		
		// reset
		for(int i = 0; i < mid; ++i) {
			cntb[b[i]]--;
		}
		
		if(can) {
			res = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
