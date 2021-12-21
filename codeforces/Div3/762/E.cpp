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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n;
int a[MAXN1];
bool f[MAXN1];
int m[MAXN1];
int cnt[MAXN1];
int g[MAXN1];

void solve() {
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	sort(a, a + n);
	memset(f, 0, sizeof(f[0])*(n+1));
	memset(m ,0,sizeof(m[0])*(n+1));
	memset(cnt,0, sizeof(cnt[0])*(n+1));
	memset(g, 0, sizeof(g[0])*(n+1));
	for(int i=0;i < n;++i) {
		f[i] = ((i == 0 || (i > 0 && f[i-1])) && a[i] <= i);
		cnt[a[i]]++;
	}
	int id = 0;
	int pre = 0;
	
	for(int i=0;i<=n;++i) {
		int l = lower_bound(a + i, a + n, i) - a;
		int r = upper_bound(a + i, a + n, i) - a;
		if(i == 0) {
			cout << (r-l) << " ";
		}
		else if(!f[i-1]) {
			cout << -1 << " ";
		}
		else {
			g[i] = cnt[a[id]];
			pre += (i - a[id]);
			if(g[i-1] == 1) {
				cout << pre*2 + (r-l) << " ";
			}
			else cout << pre << " ";
			
			
			while(id < n && a[id] <= i) id++;
			id--;
		}
	}
	cout << "\n";
}

signed main() {
	fast_cin();
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}