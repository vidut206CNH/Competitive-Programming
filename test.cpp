#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


const int N1 = 2e5+5;
const int N2 = 1e6 + 5;



int main() {
	fast_cin();
	int t,n,maxx,k;
	int a[105];
	cin >> t;
	while(t--) {
		maxx = 0;
		cin >> n >> k;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			maxx = max(maxx,a[i]);
		}
		for(int i=1;i<=n;++i) k -= (maxx-a[i]);
		cout << ((k >= 0 && k%n==0) ? "YES" : "NO");
		cout << "\n";
	}
}
