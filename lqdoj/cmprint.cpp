#include<bits/stdc++.h>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	while (a[0] == '0') {
		a.erase(a.begin());
	}
	while (b[0] == '0') b.erase(b.begin());
	if (a.size() > b.size()) {
		cout << '>';
		return 0;
	}
	if (a.size() < b.size()) {
		cout << '<';
		return 0;
	}
	reverse(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) {
			cout << '>';
			return 0;
		}
		if (a[i] < b[i]) {
			cout << '<';
			return 0;
		}
	}
	cout << '=';
}