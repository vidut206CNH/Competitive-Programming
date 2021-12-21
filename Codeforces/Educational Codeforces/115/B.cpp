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

bool a[6][1005];

int n,x,cnt=0,sum,l,r;

void solve() {
	cin >> n;
	for(int i=1;i<=5;++i) memset(a[i],0,sizeof(a[i]));
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=5;++j) {
			cin >> x;
			a[j][i] = x;
		}
	}
	for(int i=1;i<=4;++i) {
		for(int j=i+1;j<=5;++j) {
			sum = 0;
			l = 0;
			r = 0;
			for(int k=1;k<=n;++k) {
				sum += (a[i][k] | a[j][k]);
				l += a[i][k];
				r += a[j][k];
			}
			if(sum==n && l >= n/2 && r >= n/2) {
				cout << "YES";
				return;
			}
		}
	}
	cout << "NO";
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