#include<bits/stdc++.h>

using namespace std;

void solve(int n) {
	for (int i = '1'; i <= '8'; ++i) {
		cout << (char)(i + n - 8 * (i + n > '8'));
	}
}

int main() {
	int cnt1 = 0, cnt2 = 0, cnt;
	char ch;
	while (cin >> ch) {
		if (ch == 'R') cnt1++;
		else cnt2++;
	}
	cnt1 %= 8;
	cnt2 %= 8;
	if (cnt1 > cnt2) {
		cnt = cnt1 - cnt2;
		solve(8 - cnt);
	}
	else solve(cnt2 - cnt1);
}