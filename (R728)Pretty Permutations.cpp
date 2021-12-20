#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	int arr[t];
	for (int i=0;i<=t-1;++i) {
		cin >> arr[i];
	}
	for (int i=0;i<=t-1;++i) {
		if (arr[i]%2==0) {
			for (int j=1;j<=arr[i];j=j+2) {
				cout << j+1 << " " << j << " ";
			}
		}
		else {
			cout << 3 << " " << 1 << " " << 2 << " ";
			for (int j=4;j<=arr[i];j=j+2) {
				cout << j+1 << " " << j << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}