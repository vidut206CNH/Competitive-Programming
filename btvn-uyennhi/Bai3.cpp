/*
 Author: Le Nguyen Uyen Nhi
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0, b = 1, c = 1;
	int i = 1;
	while (i <= n) {
		cout << c << ' ';
		c = a + b;
		a = b;
		b = c;
		i++;
	}
}