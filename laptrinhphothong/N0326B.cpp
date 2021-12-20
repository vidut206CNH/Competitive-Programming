#include <iostream>

using namespace std;

int main() {
	long long n,S;
	cin >> n;
	S = (n*(n+1)*(2*n+1)/6)%100;
	if (S<=9) {
		cout << 0 << S;
	}
	else {
	cout << S;
	}
}