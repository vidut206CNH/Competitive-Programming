#include <iostream>

using namespace std;

int main() {
	long k,n,rev_n=0;
	cout << "Nhap n: ";
	cin >> n;
	while (n != 0) {
		k = n%10;
		rev_n = rev_n*10 + k;
		n /= 10;
		}
	}
	cout << "Reverse num is: " << rev_n;
	return 0;

}