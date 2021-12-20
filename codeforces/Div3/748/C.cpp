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

void solve() {
	cin >> n >> k;
	int ans = 0;
	int suf[k+5],a[k+5];
	memset(suf,0,sizeof(suf));
	for(int i=1;i<=k;++i) {
		cin >> a[i];
	}
	sort(a+1,a+k+1);
	for(int i=k;i>0;--i) {
		suf[i] = suf[i+1] +  n - a[i] + (a[i] == a[i+1]);
	}
	for(int i=1;i<=k;++i) {
		//cout << suf[i] << ' ';
		if(suf[i] <= n) {
			cout << k - i + 1;
			return;
		}
	}
	cout << 0;
}
/*

*/
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