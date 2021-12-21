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
const int nMax = 2e5+5;

int n,a[nMax],sum,q,ans=0;
double k,tmp;

void solve() {
	cin >> n;
	sum = 0;
	ans = 0;
	set<int> st;
	map<int,int> mp;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		sum += a[i];
		st.insert(a[i]);
		mp[a[i]]++;
	}
	k = 1.0*sum/n;
	tmp = k*(n-2);
	if(tmp - (int)tmp > 0) {
		cout << 0;
		return;
	}
	q = sum - (int)tmp;
	for(auto t : st) {
		if(t > q/2) break;
		if(2*t < q) ans += mp[t]*mp[q-t];
		else ans += (mp[t]-1)*mp[t]/2;
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