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

int t;
int n,k;
int a[MAXN1];
int st[4*MAXN1];

void update(int id, int l, int r, int pos, int val) {
	if(r < pos || pos < l) return;
	if(l ==  r) {
		st[id] += val;
		return;
	} 
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, pos, val);
	update(id << 1|1, mid + 1, r, pos, val);
	st[id] = max(st[id << 1], st[id << 1|1]);
}






signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int ans = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int low = *min_element(a + 1, a + n + 1);
		int high = *max_element(a + 1, a + n + 1);
		
		int l = 1;
		for(int i = 1; i <= n; ++i) {
			update(1, low, high, a[i], +1);
			while(i - l + 1 - st[1] > k) {
				update(1, low, high, a[l], -1);
				++l;
			}
			ans = max(ans, i - l + 1);
		}
		
		
		// clear
		memset(st, 0, sizeof st);
		
		cout << ans << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}