#include<bits/stdc++.h>

using namespace std;

int main() {
	string s, cmp, s1;
	getline(cin, s);
	stringstream ss(s);
	cin >> cmp;
	int cnt = 0;
	while (ss >> s1) {
		if (s1.size() == cmp.size()) {
			bool chk = 1;
			for (int i = 0; i < s1.size(); ++i) {
				if (cmp[i] != '?' && cmp[i] != s1[i]) {
					chk = 0;
					break;
				}
			}
			if (chk) cnt++;
		}
	}
	cout << cnt;
}