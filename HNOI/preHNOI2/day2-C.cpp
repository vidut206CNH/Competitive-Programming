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

const int MOD = 1e9;
const int MAXN1 = 1e3+5;
const int MAXN2 = 2e5 + 5;


int n,m;
int dp[6][MAXN1][MAXN1];
int a[5];
signed main() {
	fast_cin();
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	dp[0][1][0] = 1;
	int ans = 0;
	for(int i=1;i<=n;++i) {
		for(int w = 0;w <= m;++w) {
			for(int val=0;val <= a[i];++val) {
				if(val > w) break;
				dp[i][val][w] = dp[i-1][a[i-1] + 1][w - val];
				//cout << dp[i][val][w] << " ";
				dp[i][a[i] + 1][w] = (dp[i][a[i] + 1][w] + dp[i][val][w])%MOD;
			}
			if(w%9==0 && i==n) {
				ans =  (ans + dp[i][a[i] + 1][w])%MOD;
			} 
		}
		//cout << "\n";
	}
	cout << ans;
	return 0;
}