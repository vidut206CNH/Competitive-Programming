// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
using namespace std;


const int N1 = 2e5+5;
const int N2 = 1e6 + 5;
const int mod = 1e9 + 7;

bool chk(int A,int B) {
	string ta = to_string(A);
	string tb = to_string(B);
	return ta < tb; 
}


int powz(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

int a,b;
int f[100005];

signed main() {
	fast_cin();
	cin >> a >> b;
	unordered_map<int,int> dp;
	int ans = 0;
	//if(a < (int)1e5) {
		// for(int cur=b;cur >= a;--cur) {
			// int sum = 1;
			// for(int k=cur + 1;k <= b;++k) {
				// if(chk(cur,k) == 0) continue;
				// sum = (sum + dp[k])%mod;
			// }
			// dp[cur] = sum;
			// ans = (ans + dp[cur])%mod;
			// cout << sum << "\n";
		// }
		// cout << ans + 1;
	//}
	//else {
	for(int cur = b;cur >= a;--cur) {
		int sum = (min(powz(10, (int)to_string(cur).size())-1, b) - cur);
		//cout << sum + 1 << "\n";
		ans = (ans + sum + 1)%mod;
	}
	cout << ans + 1;
	//}
}