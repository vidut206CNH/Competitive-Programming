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

int a[nMax],cnt[nMax];
int n,k,t,ans=0;

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;++i) {
		if(cnt[i]) ans += (cnt[i] -1 )*cnt[i]/2;
	}
	for(int i=1;i<=n;++i) {
		t = cnt[a[i]];
		cout << ans - (t*(t-1)/2 - (t-1)*(t-2)/2) << '\n';
	}
	
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