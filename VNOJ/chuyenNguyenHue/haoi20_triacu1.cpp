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
#define eps 1e-9
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int n,res;
pii p[20005];
int f[20005];
int chk(int a,int b,int c) {
	//if(c*c == a*a+b*b) return 1;
	return (acos(1.0*(c*c-b*b-a*a)/(-2*a*b)) > acos(0.0));
}

int bins(const pii &a,const pii &b, int l,int r) {
	int mid,ans=l-1;
	while(l<=r) {
		mid = (l+r)/2;
		if(a.fi + b.fi <= p[mid].fi || chk(a.fi,b.fi,p[mid].fi)) {
			r = mid - 1;
		}
		else {
			ans = max(ans,mid);
			l = mid + 1;
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> p[i].fi >> p[i].se;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i) {
		f[i] = f[i-1] + p[i].se;
	}
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<n;++j) {
			int t = bins(p[i],p[j],j+1,n);
			res += (p[i].se*p[j].se*(f[t] - f[j]));
		}
		//cout << res << '\n';
	}
	cout << res;
	
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