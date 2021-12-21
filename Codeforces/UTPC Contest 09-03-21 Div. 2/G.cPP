#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<bool> a(21, 0);
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		a[x * y] = 1;
	}
	for (int i = 1; i < 4; ++i) {
		for (int j = i + 1; j <= 4; ++j) {
			for (int k = j + 1; k <= 5; ++k) {
				if ((a[i * j] && a[j * k] && a[i * k]) || !(a[i * j] || a[j * k] || a[i * k])) {
					cout << "Happy Doggos!";
					return 0;
				}
			}
		}
	}
	cout << "Sad Doggos...";

}