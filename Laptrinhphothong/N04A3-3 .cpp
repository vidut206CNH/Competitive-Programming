#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	long long k;
	cin >> n;
	for (int i=1;i<=n;++i) {
		long long a;
		cin >> a;
		if (a>0) {
			k = a;
		}
	}
	cout << k;
}