#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll rem(ll n) {
	ll a = 123456789;
	if (n<=26) {
		return pow(2,n);
	}
	else {
		ll b = rem(n-26)*pow(2,26); 
		return(b%a);
	}
}

int main() {
	ll n;
	cin >> n;
	cout << rem(n-1);
}