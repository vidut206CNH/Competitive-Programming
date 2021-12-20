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

char a[1005][1005];
int m,n,cnt=0,tmp;
int dx[] = {0,1,-1};
int dy[] = {0,1,-1};
void solve() {
	cin >> m >> n;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	int maxx = 0;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			if(a[i][j]=='#') {
				for(int x=0;x<3;++x) {
					for(int y=0;y<3;++y) {
						if(!(x+y==0) && a[i+dx[x]][j + dy[y]] == '#') cnt++;
					}
				}
			}
			else {
				tmp = 0;
				for(int x=0;x<3;++x) {
					for(int y=0;y<3;++y) {
						if(!(x+y==0) && a[i+dx[x]][j + dy[y]] == '#') tmp++;
					}
				}
				maxx = max(maxx,tmp);
			}
		}
	}
	cout << cnt/2 + maxx;
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