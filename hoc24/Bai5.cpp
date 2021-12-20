#include <iostream>

using namespace std;

long long d(long long a) {
	long long sum=0;
	for (long long i=1;i<=a;++i) {
		if (a%i==0) {
			sum +=1;
		}
	}
	return sum;
}
long long f(long long n) {
	long long sum=0;
	for (long long i=1;i<=n;++i) {
		if (n%i==0) {
			sum += d(i);
		}
	}
	return sum;
}

int main() {
	long long n;
	cin >>n;
	cout << f(n);
}