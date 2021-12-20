#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0, res;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'T') cnt1 = (cnt1 + 1) % 4;
		else cnt2 = (cnt2 + 1) % 4;
	}
	res = (cnt1 - cnt2 + 4) % 4;
	if (res == 0) cout << 'B';
	else if (res == 1) cout << 'T';
	else if (res == 2) cout << 'N';
	else cout << 'D';
}