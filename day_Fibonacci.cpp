#include <iostream>

using namespace std;

int main() {
	int n,a1 = 0, a2 = 1, a_i;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Day Fibonacci tu 1 den n la: " << a1 << "," << a2 << ",";
	a_i = a1+a2;
	for (a_i;a_i <= n;a_i = a1+a2) {
		if (a_i + a2 > n) cout << a_i << ".Het roi!";
		else cout << a_i << ",";
		a1 = a2;
		a2 = a_i;
	}
	return 0;
}