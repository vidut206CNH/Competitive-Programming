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
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int n,q;
int a[nMax],f[nMax];

int lowb(int l,int r,int &k) {
	int mid,ans = r,m = r-l+1;
	while(l<=r) {
		mid = (l+r)/2;
		if(m*a[mid] > k) {
			ans = min(mid,ans);
			r = mid-1;
		}
		else l = mid + 1;
	}
	return ans-1;
}

void solve() {
	cin >>n >> q;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		f[i] = f[i-1] + a[i];
	}
	int l,r;
	for(int i=1;i<=q;++i) {
		cin >> l >> r;
		int d =(f[r] - f[l-1]);
		int t = lowb(l,r,d);
		if((r-l+1)*a[t+1] > d) {
			cout << 1 << " " << t;
		}
		else cout  << a[t+1] - a[t] +1 << " " << t;
		cout << "\n";
	}
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << "\n";
		--t;
	}
	return 0;
}