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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int INF = 1e17;

int n,k;
int a[35];
int cnt[105];
int f[105];

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		memset(cnt,0,sizeof cnt);
		
		cin >> n >> k;
		
		
		f[0] = 1;
		for(int i=1;i<=60;++i) {
			if(INF/k < f[i-1]) {
				f[i] = INF;
			} else f[i] = f[i-1]*k;
		}
			
		bool bad = 0;
		
		for(int i=1;i <=n;++i) {
			cin >> a[i];
			if(bad) continue;
			
			while(a[i]) {
				int l = 0,r = 60,ans = 0;
				while(l <= r) {
					int mid =(l+r) >> 1;
					if(f[mid] <= a[i]) {
						l = mid + 1;
						ans = max(ans , mid);
					} else r = mid - 1;
				}
				a[i] -= f[ans];
				cnt[ans]++;
				if(cnt[ans] > 1) {
					bad = 1;
					break;
				}
			}
		}
		
		cout << (bad ? "NO\n" : "YES\n");
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}