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
const int nMax = 1e5+5;

int d[nMax],cost[nMax],n,ans=0,tmp;

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) cin >> d[i];
	for(int i=1;i<=n;++i) cin >> cost[i];
	int i=1,j;
	while(i<=n) {
		j = i;
		tmp = 0;
		while(j <= n && cost[j] >= cost[i]) {
			tmp += d[j];
			j++;
		}
		ans += tmp*cost[i];
		i = j;
		//cout << ans << ' ' << i << '\n';
	}
	cout << ans;
	
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