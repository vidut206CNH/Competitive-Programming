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
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e7+5;
vector<int> pri;
bool chk[nMax];
void sieve(int n) {
	for(int i=2;i<=nMax-5;++i) {
		if(!chk[i]) {
			pri.pb(i);
			for(int j=i*i;j<=nMax-5;j+=i) chk[j] = 1;
		}
	}
}
int n;
void solve() {
	sieve(n);
	cin >> n;
	int ans = 0;
	for(int i=0;pri[i]*pri[i]<n;++i) {
		if(cbrt(n) >= pri[i]) ans++;
		int t = lower_bound(pri.begin()+i+1,pri.end(),n/pri[i]) - pri.begin();
		if(pri[t]*pri[i]>n) --t;
		ans += (t-i);
	}
	cout << ans;
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << "\n";
		--t;
	}
	return 0;
}