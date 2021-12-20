#include<bits/stdc++.h>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int cnt = 0;
	vector<int> a1(150, 0), a2(150, 0);
	for (int i = 0; i < s1.size(); ++i) a1[s1[i]]++;
	for (int i = 0; i < s2.size(); ++i) a2[s2[i]]++;
	for (int i = 'a'; i <= 'z'; ++i) {
		if (a1[i]*a2[i] == 0) {
			cnt += a2[i] + a1[i];
		}
	}
	cout << cnt;
}