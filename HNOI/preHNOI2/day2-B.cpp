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
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 2e5 + 5;

int n,d;
int a[2*MAXN2];
int f[2*MAXN2];
int g[2*MAXN2];

signed main() {
	fast_cin();
	cin >> n >> d;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=n+1;i<=2*n;++i) a[i] = a[i-n];
	for(int i=1;i<=2*n;++i) {
		f[i] = f[i-1] + a[i];
		g[i] = g[i-1] + (a[i] + 1)*a[i]/2;
	}
	int ans = 0;
	for(int i=n+1;i<=2*n;++i) {
		int cur = d,id = i,sum=0;
		id = lower_bound(f, f + i, f[i] - d) - f;
		sum = g[i] - g[id];
		
		//cout << sum << " ";
		
		cur = d - (f[i] - f[id]);
		
		//cout << f[i] - f[id] << " ";
		
		sum += ((a[id]+1)*a[id]/2 - (a[id] - cur+1)*(a[id] - cur)/2);
		
		
		//cout << sum << "\n";
		
		ans = max(sum, ans);
	}
	cout << ans;

	
	return 0;
}