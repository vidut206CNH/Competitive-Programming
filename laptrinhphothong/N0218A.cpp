#include <iostream>

using namespace std;

int main() {
	long long a,b;
	cin >> a >> b;
	if ((a-b)%2==0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}