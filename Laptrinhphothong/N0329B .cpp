#include <iostream>

using namespace std;

long fraction(int n) {
	if(n==1) {
		return 1;
	}
	else {
		return n*fraction(n-1);
	}
}

int main() {
	int n;
	long res;
	cin >> n;
	res = fraction(n);
	cout << n << '!' << " = " << res;
}