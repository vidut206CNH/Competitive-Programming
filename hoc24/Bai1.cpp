#include<iostream>
#include <string>
using namespace std;

int main() {
	int i;
	cin >> i;
	string arr[10]={"one","two","three","four","five","six","seven","eight","nine","ten"};
	string arr1[9]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	string arr2[10] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	if (i<=10) {
		cout << arr[i-1];
	}
	if ((i<=19) && (i>10)) {
		cout << arr1[i-11];
	}
	if (i>=20) {
		if (i%10==0) {
			cout << arr2[i/10-2];
		}
		else {
			cout << arr2[i/10-2] << '-' << arr[i%10-1];
		}
	}
}