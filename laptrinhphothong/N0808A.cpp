#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long n,cnt=0;
	cin >> n;
	for (long i=1;i<=sqrt(n);++i) {
		if (n%i==0) {
			if (n/i == i) {
				cnt++;
			}
			else {
				cnt = cnt + 2;
			}
		}
	}
	cout << cnt;
}