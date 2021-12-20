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
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e16;
const int MINN = -2e9;
const int nMax = 1e6+5;

int a,b,ans,prod=1,l,r,sz;
int pri[] = {0,2,3,2,5,1,7,2,3,1,11,1,13,1,1,2,17,1,19,1};
void solve() {
	cin >> a >> b;
	ans = b-a+1;
	sz = ans;
	int i=1;
	for(;i<=50;++i) {
		if(prod > MAXX) break;
		prod = lcm(prod,i);
		cout << prod  << ' ' << i <<   '\n';
	}
	cout << prod << ' ' << i;
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