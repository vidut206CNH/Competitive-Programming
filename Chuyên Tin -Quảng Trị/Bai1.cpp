#include <iostream>
#include<iomanip>

using namespace std;

int sum(int x) {
	if (x == 1) return 0;
	if (x == 2) return 1;
	else {
		return (x - 1 + sum(x-1));
	}
}

int main() {
	int M,N,k;
	cout << "Nhap N: ";
	cin >> N;
	cout << "Nhap M: ";
	cin >> M;
	k = sum(N) + sum(M);
	cout << "\n" << "So cach chon la: " << k;
	return 0;
}