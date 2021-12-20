#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	stack<char> st;
	cin >> s;
	int cnt1 = 0, cnt2 = 0, n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') cnt1++;
		if (s[i] == ')') cnt2++;
	}
	if (cnt1 != cnt2) {
		cout << -1;
		return 0;
	}
	int j = 1;
	while (j < n) {
		if (j == 1) st.push(s[0]);
		while (!st.empty() && st.top() == '(' && s[j] == ')' && j < n) {
			st.pop();
			j++;
		}
		if (!st.empty() && s[j] == '(' && st.top() == ')') {
			cout << j;
			return 0;
		}
		st.push(s[j]);
		j++;
	}
	cout << 0;
}