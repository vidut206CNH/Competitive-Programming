#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (a==0) return b;
	if (b==0) return a;
	if a>b return gcd(b,a-b);
	else return gcd(a,b-a);
}

int main() {
    int a,b;
    cout << "Nhap 2 so a,b can tinh: ";
    cin >> a >> b;
    cout << "gcd(a,b) la: " << gcd(a,b);
    return 0;
}
