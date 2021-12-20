#include <iostream>

using namespace std;

int main() {
	int n;
	cin >>n;
	long arr[n];
	for (int i=0;i<=n-1;++i) {
		cin >> arr[i];
	}
	for (int i=0;i<=n-1;++i) {
		if(arr[i]%4==0) {
			if (arr[i]%400==0) {
				cout << "YES";
			}
			else if (arr[i]%100==0) {
				cout << "NO";
			}
			else {
				cout << "YES";
			}
		}
		else {
			cout << "NO";
		}
		cout << "\n";
	}
}