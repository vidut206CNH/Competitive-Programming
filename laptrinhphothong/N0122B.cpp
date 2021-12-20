#include <iostream>

using namespace std;

int main() {
	long long  n;
	cin >> n;
	if (n%2!=0) {
		cout << n;
	}
	else {
		for (long long i=n/2;i>=1;--i) {
			if ((n%i==0) && (i%2!=0)) {
				cout << i;
				break;
			}
		}
	}
}