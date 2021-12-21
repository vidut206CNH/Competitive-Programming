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
const int nMax = 1e5+5;

int n,m,x,y,ans=0;
int a[50005];
int f[1005];
int mark[1005];
void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	cin >> m;
	for(int i=1;i<=m;++i) {
		cin >> x >> y;
		if(mark[x]) mark[x] = min(mark[x],y);
		else mark[x] = y;
	}
	for(int i=1000;i>=1;--i) {
		f[i] = nMax;
		if(f[i+1]) f[i] = f[i+1];
		if(mark[i]) f[i] = min(f[i],mark[i]);
	}
	for(int i=1;i<=n;++i) {
		ans += f[a[i]];
	}
	cout << ans;
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}