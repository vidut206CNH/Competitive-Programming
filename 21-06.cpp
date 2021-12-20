// đếm số ước nguyên tố của 1 số nguyên dương x> 2
#include <iostream>

using namespace std;

int is_prime(int a){
	for(int i =2;i<= a;i++) {
		if (i == a) return 1;
		if (i==a-1) return 1;
		if (a%i == 0) return 0; 
	}
	return 0;
}
int main() {
	int x;
	cout << "Nhap x: ";
	cin >> x;
	int k = 0;
	for (int i = 2;i<x;i++) {
		if ((x%i == 0) && (is_prime(i) == 1)) {
			++k;
		}
	}
	cout << "So uoc nguyen to cua x la: " << k;
	return 0;
}