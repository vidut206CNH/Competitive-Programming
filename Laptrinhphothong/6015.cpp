#include <iostream>

using namespace std;

typedef long long ll;


int main() {
	ll n;
	cin >> n;
	ll arr[n];
	for (ll i=0;i<=n-1;++i) {
		cin >> arr[i];
	}
	ll arr1[n];
	for (ll i=0;i<=n-1;++i) {
		cin >> arr1[i];
	}

	for (ll i=0;i<n-1;++i) {
		for (ll k=i+1;k<=n-1;++k) {
			if (arr[k]<arr[i]) {
				ll temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
		}
	}

	for (ll i=0;i<n-1;++i) {
		for (ll k=i+1;k<=n-1;++k) {
			if (arr1[k]>arr1[i]) {
				ll temp = arr1[i];
				arr1[i] = arr1[k];
				arr1[k] = temp;
			}
		}
	}

	for (ll i=0;i<=2*n-1;++i) {
		if (i<=n-1) {
			cout << arr[i] << " ";
		}
		else {
			cout << arr1[i-n] << " ";
		}
	}

}