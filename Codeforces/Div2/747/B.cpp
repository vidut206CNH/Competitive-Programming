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

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int powz(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b /= 2;
	}
	return res;
}

void solve() {
	int n,k,ans=0;
	cin >> n >> k;
	deque<int> de;
	while(k) {
		de.pb(k%2);
		k /= 2;
	}
	int i = 0;
	while(!de.empty()) {
		int t = de.front();
		de.pop_front();
		ans = (ans + t*powz(n,i))%MOD;
		i++;
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