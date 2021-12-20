/*
 Author: Le Nguyen Uyen Nhi
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	long double tmp, tmp1, x, y;
	bool chk1 = 1, chk2 = 1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> y;
		if (i == 1) {
			tmp = y - x;
			tmp1 = y / x;
		}
		if (i > 1 && tmp != y - x) {
			chk1 = 0;
		}
		if (i > 1 && (x == 0 || tmp1 != y / x )) {
			chk2 = 0;
		}
		x = y;
	}
	if (chk1 || chk2) cout << "Yes";
	else cout << "No";
}