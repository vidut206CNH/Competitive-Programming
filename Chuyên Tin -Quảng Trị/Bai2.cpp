#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n,sum=0;
	cout << "\n Nhap n: ";
	cin >> n;
	for (int i = 1;i<n;++i) {
		if (n%i == 0) {
			sum += i;
		}
	}
	if (sum == n) {
		cout << "La so hoan hao";
	}
	else {
		cout << "Khong la so hoan hao";
	}
	return 0;
}