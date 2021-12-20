#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
	ll t;
	cin >> t;
	ll countarr[t];
	for (ll k=0;k<=t-1;++k) {
		ll n;
		cin >> n;
		ll arr[n],count=0;
		for (ll i=0;i<=n-1;++i) {
			cin >> arr[i];
		}
		for (ll i=0;i<=n-1;++i) {
			for (ll j=1+i;j<=n-1;++j) {
				if (arr[i]*arr[j] == i+j+2) {
					count += 1;
				}
			}
		}
		countarr[k] = count;
	}
	for (ll i=0;i<=t-1;++i) {
		cout << countarr[i] << "\n";
	}
}