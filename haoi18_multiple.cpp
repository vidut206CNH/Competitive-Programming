/* 
	link problem: https://oj.vnoi.info/problem/haoi18_multiple
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

bool chk[nMax+3];
vector<int> pri;

int finds(int n) {
	int l =2, r = pri.size()-1,ans = 0,mid;
	while(l <= r) {
		mid = (l+r)/2;
		if(pri[mid-2]*pri[mid-1]*pri[mid] == n) return n;
		if(pri[mid-2]*pri[mid-1]*pri[mid] < n) {
			ans = max(ans,pri[mid-2]*pri[mid-1]*pri[mid]);
			l = mid+1;
		}
		else r = mid-1;
	}
	return ans;
}

void sieve() {
	for(int i=2;i*i<=nMax;++i) {
		if(!chk[i]) {
			for(int j=i*i;j<=nMax;j+=i) chk[j] = 1;
		}
	}
	for(int i=2;i<=nMax;++i) {
		if(!chk[i]) pri.pb(i);
	}
}

int n;
void solve() {
	cin >> n;
	int ans = finds(n);
	if(!ans) cout << -1;
	else cout << ans;
	
}


int32_t main() {
	fast_cin();
	int t = 1;
	cin >> t;
	sieve();
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}