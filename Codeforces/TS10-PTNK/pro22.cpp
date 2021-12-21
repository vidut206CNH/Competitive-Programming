#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int i = 0, temp, res = 0;
	while (i < s.size()) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp = s[i] - 48;
			int j = i + 1;
			while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
				temp *= 10;
				temp += (s[j] - 48);
			}
			res = max(res, temp);
			i = j;
		}
		else i++;
	}
	cout << res;
}