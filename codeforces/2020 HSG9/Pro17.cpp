#include<bits/stdc++.h>

using namespace std;

int main() {
	int a, b, x, y, res = 0;
	cin >> a >> b >> x >> y;
	res += (b / x - a / x + (a % x == 0));
	res += (b / y - a / y + (a % y == 0));
	int lcm = x * y / __gcd(x, y);
	res -= (b / lcm - a / lcm + (a % lcm == 0));
	cout << res;
}
