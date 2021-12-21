#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, s1;
	char c;
	getline(cin, s);
	getline(cin, s1);
	ll n = s.size(), cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == s1[n - i - 1]) cnt++;
	}
	cout << cnt;
}