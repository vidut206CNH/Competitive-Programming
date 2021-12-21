#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll n,k,arr[n];
	cin >> n >> k;
	ll count = 0;
	for (ll i=0;i<=n-1;++i) {
		cin >> arr[i];
		if (k==arr[i]) {
			count += 1;
		}
	}
	cout << count;
}