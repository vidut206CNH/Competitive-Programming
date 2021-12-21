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

int sz,f0[1005],f1[1005],sf1,sf0;

void solve() {
	string s;
	cin >> s;
	sf0 = 0;
	sf1 = 0;
	int sz = s.size(),ans=MAXX;
	for(int i=0;i<sz;++i) {
		f1[i+1] = f1[i];
		f0[i+1] = f0[i];
		if(s[i]- 48 == 1) {
			f1[i+1]++;
			sf1++;
		}
		else {
			f0[i+1]++;
			sf0++;
		}
		//cout << f0[i+1] << ' ' << f1[i+1] << "\n";
	}
	for(int i=0;i<sz;++i) {
		if(i==sz-1 || s[i]!=s[i+1]) {
			if(s[i]=='0') {
				ans = min(ans,f1[i+1] + sf0 - f0[i+1]);
			}
			else ans = min(ans,f0[i+1] +sf1 - f1[i+1]);
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
		cout << "\n";
		--t;
	}
	return 0;
}