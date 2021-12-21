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

int n;
int a[nMax];
int f[3];

void solve() {
	cin >> n;
	int ans = 0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		f[a[i]%3]++;
	}
	int cur = 0;
	while(!(f[0]==f[1] && f[1]==f[2])) {
		while(f[cur%3] > n/3) {
			f[(cur+1)%3]++;
			f[cur%3]--;
			ans++;
		}
		cur++;
		//break;
	}
	cout << ans;
}


int32_t main() {
	fast_cin();
	int t = 1;
	cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}