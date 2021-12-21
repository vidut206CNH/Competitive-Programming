#include <iostream>

using namespace std;

int main() {
	long long a,b;
	cin >> a >> b;
	long long max = a;
	if (a>=0) {
		if (b>a) {
			max = b;
		}
		if ((b+a) <0) {
			max = b;
		}
	}
	else {
		if ((b+a) >0) {
			max = b;
		}
		if ((b-a) <0) {
			max = b;
		}
	}
	cout << max;
}