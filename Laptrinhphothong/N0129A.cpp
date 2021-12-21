#include <iostream>

using namespace std;

int main() {
	long long a,b,c;
	cin >> a >> b >> c;
	a = a%c;
	b = b%c;
	cout << (a+b)%c;
}