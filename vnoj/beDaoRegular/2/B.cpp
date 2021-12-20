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

vector<int> p(25),ans;
int X;
int n,sum=0;
int a[25];

bool chk() {
	X = 0;
	for(int i=1;i<=n;++i) {
		X += p[i];
	}
	X = sum - 2*X;
	if(X==1 || X == 0) return 0;
	for(int i=2;i*i<=X;++i) {
		if(X%i==0) return 0;
	}
	return 1;
}

void backtr(int k,bool ok) {
	if(k > n) {
		if(chk()) {
			ans.pb(X);
		}
		return;
	}
	p[k] = ((ok) ? a[k] : 0);
	for(int i=0;i<=1;++i) {
		backtr(k+1,i);
	}
	return;
}

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		sum += a[i];
	}
	for(int i=0;i<=1;++i) {
		backtr(1,i);
	}
	sort(ans.begin(),ans.end());
	cout << ans.back();
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