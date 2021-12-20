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
#define PI acos(-1)
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

double r,x,ans=0,t,q;

void solve() {
	cin >> r >> x;
	t = sqrt(2.0*r*r - 2.0*r*r*cos(72.0*PI/180));
	q = sqrt(2.0*r*r - 2.0*r*r*cos(144.0*PI/180));
	ans = q*q*sin(108.0*PI/180)/2 + q*(q+x)*sin(36.0*PI/180)/2;
	ans += r*r*(72.0*PI/180 - sin(72.0*PI/180))/2;
	cout << fixed << setprecision(9) << ans;
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