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

int sz;
string n;
vector<int> ans(12),res,num(12);

bool chk(int k) {
	if(k==1 || k==0) return 0;
	for(int i=2;i*i<=k;++i) {
		if(k%i==0) return 0;
	}
	return 1;
}

void backtracking(int id,int k, int t) {
	if(k-id > sz-t) return;
	ans[id] = num[t];
	if(k==id) {
		int p = 0;
		for(int i=1;i<=k;++i) {
			p = p*10 + ans[i];
		}
		if(chk(p)) {
			res.pb(p);
		}
		return;
	}
	for(int i=t+1;sz - i >= k-id-1;++i) {
		backtracking(id+1,k,i);
	}
}


void solve() {
	cin >> n;
	sz = n.size();
	for(int i=0;i<sz;++i) {
		num[i+1] = n[i] -'0';
	}
	for(int i=sz;i>0;--i) {
		for(int j=1;j+i-1 <= sz;++j) {
			if(num[j] != 0) backtracking(1,i,j);
		}
		if(!res.empty()) {
			int maxx = 2;
			for(auto x :  res) {
				maxx = max(maxx,x);
			}
			cout << maxx << ' ';
			return;
		}
	}
	cout << -1;
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