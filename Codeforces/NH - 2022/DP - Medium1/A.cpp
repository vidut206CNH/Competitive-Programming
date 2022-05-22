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
int a[MAXN1];
int val[MAXN1];
map<int,int> last;
int f[MAXN1];
int bit[MAXN1];


void update(int pos, int va) {
	for(;pos > 0; pos -= (pos & -pos)) bit[pos] += va;
}

int get(int pos) {
	int res = 0;
	for(;pos < MAXN1; pos += (pos & -pos)) res += bit[pos];
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		val[i] = i - last[a[i]] + 1;
		last[a[i]] = i;
	}
	
	f[1] = n;
	set<int> st;
	for(int i = 1; i <= n; ++i) {
		update(val[i], +1);
	}
	
	int res = 0;
	
	for(int d = 1;d <= n; ++d) {
		if(d != 1) {
			update(val[d - 1], -1);
		}
		
		res += get(d + 1);
		res -= sz(st);
		
		
		cout << res << " ";
		
		st.insert(a[n - d + 1]);
	}
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}