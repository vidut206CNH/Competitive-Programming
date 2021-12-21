#include <iostream>

using namespace std;
typedef long long ll;


int main() {
	ll n;
	cin >> n;
	for (ll i=1;i<=n;++i) {
		ll k;
		cin >> k;
		if (k<0) {
			cout << i;
			break;
		}
	}
}