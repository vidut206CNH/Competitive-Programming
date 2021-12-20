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
int n;
int a[nMax];

int bins(int l,int k) {
	int r = n,mid;
	while(l<=r) {
		mid = (l+r)/2;
		if(a[mid]==k) return mid;
		if(a[mid] < k) l =mid +1;
		else r = mid-1;
	}
	return 0;
}

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			if(bins(j+1,a[i]+a[j])) {
				cout << "YES";
				return;
			}
			if(bins(j+1,a[i]-a[j])) {
				cout << "YES";
				return;
			}
			if(bins(j+1,a[j]-a[i])) {
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