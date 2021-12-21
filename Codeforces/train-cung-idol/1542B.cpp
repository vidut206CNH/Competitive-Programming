/* 
	link problem: https://codeforces.com/problemset/problem/1542/B
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

int n,a,b,q,p;

int powz(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void solve() {
	cin >> n >> a >> b;
	if(n==1) {
		cout << "YES";
		return;
	}
	q = n%b;
	int m = powz(a,0);
	bool flag = 0;
	for(int i=1;i<=100;++i) {
		if(m>n) break;
		if(m%b == q) {
			flag = 1;
			break;
		}
		m *= a;
	}
	if(!flag) cout << "NO";
	else cout << "YES";
}


int32_t main() {
	fast_cin();
	int t = 1;
	cin >> t;
	while(t) {
		solve();
		cout << "\n";
		--t;
	}
	return 0;
}