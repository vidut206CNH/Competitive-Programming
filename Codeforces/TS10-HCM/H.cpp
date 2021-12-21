#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int k;
	cin >> k;
	stack<int> st;
	vector<int> ans;
	for (int i = 0; i < s.size(); ++i) {
		int x = s[i] - 48;
		while (!st.empty() && k > 0 && st.top() < x) {
			st.pop();
			--k;
		}
		st.push(x);
	}
	while (k) {
		st.pop();
		--k;
	}
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i];

}