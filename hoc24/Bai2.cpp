#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	long long min = a,max = b;
	if (a>b) {
		max = a;
		min = b;
	}
	if (min==0) {
		return max;
	}
	else if (max%min==0) {
		return min;
	}
	else {
		return gcd(max-min,min);
	}

}

int main() {
	long long a,b;
	cin >> a >> b;
	cout << gcd(a,b) << " ";
	a = a/gcd(a,b);
	cout << a*b;

}