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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;

int n,c1,c2;
int a[MAXN1];
int p[MAXN1];
int bit[MAXN1];
bool ok[MAXN1];

void update(int id,int val) {
	for(;id < MAXN1;id += id&-id) {
		bit[id] += val;
	}
}

int get(int id) {
	int res = 0;
	for(;id > 0;id -= id&-id) {
		res += bit[id];
	}
	return res;
}

signed main() {
	fast_cin();
	cin >> n >> c1 >> c2;
	for(int i=1;i <=n;++i) {
		cin >> a[i];
		update(a[i],1);
	}
	int ans = 0;
	for(int i=1;i<=n;++i) cin >> p[i];
	
	for(int i=1;i<=n;++i) {
		if(!ok[i]) {
			bool good = 0;
			for(int j=i+1;j <= n;++j) {
				if(!ok[j] && a[j] > a[i]) {
					int m = get(a[j] - 1);
					if(m == p[i]) {
						update(a[j], -1);
						ans += c2;
						good = 1;
						ok[j] = 1;
						break;
					}
				}
			}
			if(!good) ans += c1;
			update(a[i], -1);
			ok[i] = 1;
		}
	}
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}