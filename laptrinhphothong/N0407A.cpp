#include <iostream>

using namespace std;

int gttd(long a) {
		if (a<0) {
			return -a;
		}
		else {
			return a;
		}
	}

int main() {
	
	int n,sum=0;
	cin >> n;
	for (int i=1;i<=n;++i) {
		long a;
		cin >> a;
		sum += gttd(a);
	}
	cout << sum;
}