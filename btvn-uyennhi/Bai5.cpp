/*
 Author: Le Nguyen Uyen Nhi
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, sum = 0, t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		t = rand() % 1000;
		cout << t << ' ';
		sum += (t % 5 == 0) ? t : 0;
	}
	cout << '\n' << sum;
}