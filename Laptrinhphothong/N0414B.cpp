#include <iostream>
#pragma GCC optimize("O3")
using namespace std;

int main() {
	int n,count=1;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;++i) {
		cin >> arr[i];
		for (int j=i-1;j>=0;--j) {
			if (arr[j] == arr[i]) {
				break;
			}
			if (j==0) {
				count +=1;
			}
		}
	}
	cout << count;
}