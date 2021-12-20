#include<iostream>

using namespace std;


int main() {
	int n;
	cin >> n;
	int arr1[n], arr2[n];
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr1[i];
		cin >> arr2[i];
	}
	int MIN = arr1[0], MAX = arr2[0];
	for (int i = 1; i <= n - 1; ++i) {
		if (arr1[i] < MIN) {
			MIN = arr1[i];
		}
		if (arr2[i] > MAX) {
			MAX = arr2[i];
		}
	}
	int i = 0;
	while (i < n) {
		while (arr1[i])
		}

}