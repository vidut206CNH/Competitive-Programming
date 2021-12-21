#include <iostream>

using namespace std;

int main() {
	long long n;
	long long sum=0;
	cin >> n;
	if (n%3==0) {
		n -= 3;
	}
	else {
		n -= n%3;
	}
	if (n>0) {
		sum = ((n+3)*((n-3)/3 + 1))/2;
	}
	cout << sum;
}