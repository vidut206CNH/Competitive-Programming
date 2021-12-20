#include <iostream>
#pragma GCC optimize("O3")
using namespace std;

int count(long long n) {
	int cnt = 0;
	if (n%5==0) {
		cnt += 1;
		n /= 5;
		cnt += count(n);
	}
	return cnt;
}

int main() {
	long long n;
	cin >> n;
	cout << count(n);
}