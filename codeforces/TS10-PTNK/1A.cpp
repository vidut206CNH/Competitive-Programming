#include<bits/stdc++.h>

using namespace std;

string sol(string s, int a, int n) {
	string s1 = "";
	for (int i = 0; i < n; ++i) {
		int j = (n - a + i) % n;
		s1 += s[j];
	}
	return s1;
}


int main() {
	int n, m, cnt1 = 0, cnt2 = 0;
	string s;
	char c;
	cin >> n >> s >> m;
	for (int i = 0; i < m; ++i) {
		cin >> c;
		if (c == '1') cnt1++;
		if (c == '2') cnt2++;
	}
	cnt2 %= n;
	cnt1 %= 10;
	s = sol(s, cnt2, n);
	for (int i = 0; i < n; ++i) {
		s[i] += cnt1;
		if (s[i] > '9') s[i] -= 10;
		cout << s[i];
	}
}