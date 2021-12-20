#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x,intPart,fracPart;
	cin >> x;
	fracPart = modf(x, &intPart);
	cout << intPart << " " << fracPart;

}