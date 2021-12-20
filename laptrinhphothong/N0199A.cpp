#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long arr[n];
	for (int i=0;i<=n-1;++i) {
		long long a;
		cin >> a;
		arr[i] = 5*pow(a,3) + 3*pow(a,2) + 4*a -11;
	}
	for (int i=0;i<=n-1;++i) {
		cout << arr[i] << "\n";
	}
}