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

int n,x,y,a,b,c,d,ans;

void solve() {
	cin >> n >> x >> y >> a >> b >> c >> d;
	if(a>b) swap(a,b);
	if(c>d) swap(c,d);
	int t1 = abs(a-c);
	int t2 = abs(b-d);
	if((a-c)*(b-d)>0) {
		ans = y*min(t1,t2) + x*(abs(t1-t2));
		ans = min(ans,x*(t1+t2));
		cout << ans;
		return;
	}
	else {
		ans = y*min(t1,t2) + x*(max(t1,t2) + min(t1,t2));
		ans = min(ans, x*(t1+t2));
		cout << ans;
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