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


int a,b;

void solve() {
	cin >> a >> b;
	int ans = (b+a)*(b-a+1)/2 + (a>1);
	int l_i=a,r_i;
	for(int i=2;i<=min((int)sqrt(b),l_i-1);++i) {
		int tmp = l_i-1;
		r_i = b/i;
		l_i =(a-1+i)/i;
		if(r_i - l_i + 1 > 0) ans += i;
		r_i = min(tmp,r_i);
		l_i = max(i+1,l_i);
		if(r_i - l_i + 1 > 0) {
			ans += (r_i+l_i)*(r_i-l_i+1)/2;
		}
		//cout << ans << ' ' << r_i << ' ' << l_i << '\n';
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