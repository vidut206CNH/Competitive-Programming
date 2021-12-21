#include<bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] <= 90 && (s[i] != 'U' || s[i] != 'E' || s[i] != 'O' || s[i] != 'A' || s[i] != 'I')) {
			s[i] += 32;
		}
		if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i') {
			s[i] -= 32;
		}
	}
	cout << s << '\n';
}


int main() {
	int t;
	cin >> t;
	while (t) {
		solve();
		--t;
	}
}