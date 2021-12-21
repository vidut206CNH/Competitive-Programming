/* 
	link problem: https://oj.vnoi.info/problem/cdiv/rank/
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
const int nMax = 1e5+5;

int m1=0,m2=0,m0=0,n;
int a[nMax];
void solve() {
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		if(a[i]%3==1) m1++;
		if(a[i]%3 == 2) m2++;
		else m0++;
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