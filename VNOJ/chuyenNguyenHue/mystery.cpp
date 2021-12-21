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
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 20122007;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int n;

int powz(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b /= 2;
	}
	return res;
}

// int pows(int a, string b) {
	// int ans = 1;
	// for(int i=b.size()-1;i>=0;--i) {
		// ans = (ans* powz(a,b[i]-'0'))%MOD;
		// a = powz(a,10);
	// }
	// return ans;
// }


void solve() {
	cin >> n;
	int res = 1;
	for(int i=1;i*i<=n;++i) {
		if(n%i==0 && i*i != n) {
			res = (res*(powz(3,i) - 1))%MOD*(powz(3,n/i) - 1)%MOD;
		}
		if(i*i==n) res = res*(powz(3,i) - 1)%MOD;
	}
	cout << res;
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