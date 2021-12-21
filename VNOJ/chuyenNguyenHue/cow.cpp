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
const int nMax = 1e5+5;

int n,k;
deque<int> f,s;
int ans[nMax],a[nMax];
void solve() {
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	for(int i=1;i<=n;++i) {
		f.pb(i);
		while(!f.empty() && a[f.front()] - k > a[i]) f.pop_front();
		if(!f.empty()) {
			int j = f.front()-1;
			while(j > 0 && a[j] - k <= a[i]) {
				f.push_front(j);
				--j;
			}
		}
		ans[i] += i - f.front() + 1;
		cout << ans[i] << ' ';
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