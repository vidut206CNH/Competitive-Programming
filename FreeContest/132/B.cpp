/* 
	link problem: 
	Author : vidut_206_CNH
*/
// Ban co the doc solution khac tai: https://bit.ly/Better_Solution
// https://bit.ly/Tran_Gia_Khanh_fan_club
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int MAXN1 = 1e6+5;
const int MAXN2 = 2e5 + 5;




int32_t main() {
	fast_cin();
	int n,q;
	cin >> n >> q;
	int a[n+1];
	for(int i=1;i<=n;++i) cin >> a[i];
	while(q--) {
		int u,v;
		cin >> u >> v;
		if((v-u)%2 == 0) {
			cout << 1;
		}
		else {
			int t = v - u;
			cout << a[u + t/2 + 1] - a[u + t/2] + 1;
		}
		cout << "\n";
	}


	
	return 0;
}
