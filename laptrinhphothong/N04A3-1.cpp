#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long arr[n];
	for (int i=0;i<=n-1;++i) {
		cin >> arr[i];
	}
	for (int i=n-1;i>=0;--i) {
		cout << arr[i] << " ";
	}
}