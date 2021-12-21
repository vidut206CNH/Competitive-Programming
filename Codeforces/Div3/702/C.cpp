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

vector<int> p;
int n;
int bins(int k) {
	int l =0,r=p.size(),mid;
	while(l<=r) {
		mid = (l+r)/2;
		if(p[mid]==k) return mid;
		if(p[mid]>k) r = mid-1;
		else l = mid+1;
	}
	return -1;
}

void pre_process() {
	for(int i=1;i<=10000;++i) {
		p.pb(i*i*i);
	}
}


void solve() {
	cin >> n;
	int p_s = p.size();
	for(int i=p_s-1;i>=0;--i) {
		if(p[i] >= n) continue;
		int f = bins(n-p[i]);
		if(f!=-1) {
			cout << "YES";
			return;
		} 
	}
	cout << "NO";
	
}


int32_t main() {
	fast_cin();
	int t = 1;
	pre_process();
	cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}