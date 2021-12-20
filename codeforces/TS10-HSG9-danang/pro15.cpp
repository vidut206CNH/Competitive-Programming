#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool a[150];
	memset(a, 0, sizeof(a));
	int i = 0, cnt = 0;
	while (i < s.size()) {
		a[s[i]] = 1;
		if (a[s[i + 1]]) {
			cnt++;
			memset(a, 0, sizeof(a));
		}
		i++;
	}
	cout << cnt + 1;
}