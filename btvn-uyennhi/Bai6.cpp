/*
 Author: Le Nguyen Uyen Nhi
*/
#include<bits/stdc++.h>

using namespace std;

bool chk(int n) {
	if (n == 8) return 1;
	if (n / 10 == 0) return 0;
	int x = 0;
	while (n) {
		x += n % 10;
		n /= 10;
	}
	return chk(x);
}

int main() {
	int n;
	cin >> n;
	cout << (chk(n) ? "Yes" : "No");
}