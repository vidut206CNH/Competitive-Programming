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
const int nMax = 2e5+5;

int n,it1=0,it2=0;
bool mark[nMax];
int a[nMax],ans[nMax];
int v[nMax],u[nMax];
void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		if(!mark[a[i]]) {
			mark[a[i]] = 1;
			ans[i] = a[i];
		}
		else v[++it1] = i;
	}
	for(int i=1;i<=n;++i) {
		if(!mark[i]) u[++it2] = i;
	}
	sort(v+1,v+it1+1);
	sort(u+1,u+it2+1);
	for(int i=1;i<=it2;++i) cout << u[i] << ' ' << v[i] << '\n';
	int i=2;
	ans[it2] = v[1];
	while(i<=it2) {
		ans[u[i]] = v[i-1];
		++i;  
	}
	for(int i=1;i<=n;++i) cout << ans[i] << ' ';
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