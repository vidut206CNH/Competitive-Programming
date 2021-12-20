#include<bits/stdc++.h>

using namespace std;

string maxi(string a, string b) {
	while (a.size() < b.size()) a = '0' + a;
	while (a.size() > b.size()) b = '0' + b;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) return a;
		if (a[i] < b[i]) return b;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, res = "0";
	cin >> s;
	int i = 0;
	while (i < s.size()) {
		if (s[i] >= '0' && s[i] <= '9') {
			string temp = "";
			temp += s[i];
			int j = i + 1;
			while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
				temp += s[j];
				j++;
			}
			res = maxi(res, temp);
			i = j;
		}
		i++;
	}
	while (res[0] == '0') res.erase(res.begin());
	cout << res;
}