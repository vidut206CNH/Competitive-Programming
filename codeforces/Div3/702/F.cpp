/* 
	link problem: 
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
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 2e5+5;

int n,cnt;
int a[nMax],pref[nMax],f[nMax];

void solve() {
	cin >> n;
	memset(f,0,(n+1)*sizeof(f[0]));
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int cnt = 1,k=0;
	for(int i=1;i<=n;++i) {
		if(i==n || a[i]!=a[i+1]) {
			f[cnt]++;
			k = max(k,cnt);
			cnt = 1;
		}
		else cnt++;
	}
	for(int i=1;i<=k;++i) {
		pref[i] = pref[i-1] + f[i]*i;
		//cout << pref[i] << " ";
	}
	//cout << "\n";
	int s = 0,ans=MAXX,q = 0;
	for(int i=k;i>0;--i) {
		ans = min(ans, s + pref[i-1]);
		//cout << s + pref[i-1] << " ";
		s = s + f[i] + q;
		q += f[i];
	}
	cout << ans;
}
/*
in:
12
1 1 2 2 2 4 4 4 4 4 3 3
out:

*/

int32_t main() {
	fast_cin();
	int t = 1;
	cin >> t;
	while(t) {
		solve();
		cout << "\n";
		--t;
	}
	return 0;
}