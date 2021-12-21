#include<bits/stdc++.h>

using namespace std;

bool chk(int n) {
	if (n == 1 || n == 0) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	char c;
	int sum = 0;
	while (cin >> c) {
		sum *= 10;
		sum += c - 48;
		if (!chk(sum)) {
			cout << "KHONG";
			return 0;
		}
	}
	cout << "PHAI";
}