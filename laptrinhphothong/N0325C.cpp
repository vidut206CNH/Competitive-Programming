#include <iostream>
#include <cmath>
#pragma GCC optimize("O3")
using namespace std;

int main() {
	long long n,sum;
	cin >> n;
	sum = 0;
	for (long long i=1;i<=sqrt(n);++i) {
		if (n%i==0) {
			if (n/i == i) {
				sum += i;
			}
			else {
			sum += i + n/i;
			}
		}
	}
	cout << sum;
}