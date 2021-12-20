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
const int nMax = 1e6+5;

int n;
string s;
int a[205];

void solve() {
	cin >> n;
	memset(a,0,sizeof(a));
	cin >> s;
	for(int i=0;i<n;++i) {
		a[i] += s[i] - '0';
	}
	cin >> s;
	for(int i=0;i<n;++i) {
		a[i] += (s[i]-'0');
		if(a[i] == 2) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
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