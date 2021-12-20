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
	for (ll i=0;i<=n-2;++i) {
		for (ll k=i+1;k<=n-1;++k) {
			if (arr[k]>arr[i]) {
				ll temp = arr[k];
				arr[k] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (ll i=0;i<=n-1;++i) {
		cout << arr[i] << " ";
	}
}