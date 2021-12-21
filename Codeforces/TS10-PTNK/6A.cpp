#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	cout << max(0LL, (a * b / __gcd(a, b)) - (a + b));
}