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
const int nMax = 3e5+5;

bool chk[nMax+1];
vector<int> pri;


int n,cnt=0;
char c;
string s;
bool flag;
void solve() {
	cin >> n >> c >> s;
	flag = 0;
	for(int i=0;i<n;++i) {
		if(s[i]!=c) flag = 1;
	}
	if(!flag) {
		cout << 0;
		return;
	}
	vector<int> ans;
	for(int i=n;i>=2;--i) {
		cnt = 0;
		for(int j=i;j<=n;j+=i) {
			if(s[j-1]!=c) cnt++;
		}
		if(!cnt) {
			cout << 1 << '\n' << i;
			return;
		}
		if(cnt==1) ans.pb(i);
	}
	sort(ans.begin(),ans.end(),greater<int>());
	cout << 2 << '\n' << ans[0] << ' ' << ans[1];
	
	
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