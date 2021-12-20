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
const int nMax = 1e6+5;

int n,k;
int a[nMax];

void solve() {
	cin >> n >> k;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=(n+1)/2 + 1;i<=n;++i) {
		k -= (a[i]-a[i-1])*(i-(n+1)/2);
		if(k<0) {
			cout << a[i-1] + (k+(a[i]-a[i-1])*(i-(n+1)/2))/(i-(n+1)/2);
			return;
		}
		//cout << k << ' ' << i <<"\n";
	}
	cout << a[n] + k/((n+1)/2);
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