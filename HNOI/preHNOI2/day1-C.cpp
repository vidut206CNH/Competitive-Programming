// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;


const int N1 = 2e5+5;
const int N2 = 2e5 + 10;

int n,x;
int a[N2];
int f[N2];
int g[N2];


signed main() {
	fast_cin();
	cin >> n >> x;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=n+1;i<=2*n;++i) a[i] = a[i-n];
	for(int i=1;i<=2*n;++i) {
		f[i] = f[i-1] + a[i];
	}
	for(int id = 1;id<=2*n;++id) {
		int t = upper_bound(f + id, f + id + n, f[id-1] + x) - f;
		g[id] = (t - id);
	}
	int m = 0;
	for(int id = 1;id <= 2*n; ++id) {
		int t = lower_bound(f, f + id, f[id] - x) - f;
		
		m += (id - t);
		
		if(id >= n && id < 2*n) {
			m -= g[id - n];
			cout << m << "\n";
		}
	}
}