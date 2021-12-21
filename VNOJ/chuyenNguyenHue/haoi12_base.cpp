/* 
	link problem: https://oj.vnoi.info/problem/haoi12_base
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
const int nMax = 1e6+5;

string s,ans="";
int tmp;

char he[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

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
	cin >> s;
	for(int i=s.size()-1;i>=0;i-=4) {
		tmp = 0;
		for(int j=i;j>=max(i-3,0LL);--j) {
			tmp += powz(2,i-j)*(s[j] - '0');
		}
		ans = he[tmp] + ans;
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