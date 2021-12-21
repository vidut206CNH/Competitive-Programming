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

string s;

bool conv(char a, char b) {
	int tmp = (a-48)*10 + b - 48;
	if(tmp%25==0) return 1;
	return 0;
}

void solve() {
	cin >> s;
	int sz = s.size();
	int ans = MAXX;
	for(int i=sz-1;i>0;--i) {
		for(int j=i-1;j>=0;--j) {
			if(conv(s[j],s[i])) {
				ans = min(ans,sz - i - 1 + i-j-1);
			}
		}
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