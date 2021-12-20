#include <iostream>
#pragma GCC optimize("O3")
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long arr[n];
	for  (long long i=0;i<n;++i) {
		cin >> arr[i];
		if (arr[i]<0) {
			if (i==0) {
				cout << n;
				break;
			}
			else {
				for (long long k=i-1;k>=0;--k) {
					if (arr[k] != 0) {
						cout << arr[k];
						break;
					}
				}
				break;
			}
		}
		if (i== (n-1)) {
			cout << 0;
		}
	}
}