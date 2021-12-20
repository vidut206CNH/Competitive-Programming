#include<bits/stdc++.h>

using namespace std;

int main() {
	string s, ans = "", temp;
	cin >> s;
	int Maxl = 1, lo, hi;
	for (int i = 1; i < s.size(); ++i) {
		temp = "";
		lo = i - 1;
		hi = i;
		while (lo >= 0 && s[lo] == s[hi]) {
			temp = s[lo] + temp + s[lo];
			--lo;
			++hi;
		}
		++lo; --hi;
		if (s[lo] == s[hi] && hi - lo + 1 > Maxl) {
			Maxl = hi - lo + 1;
			ans = temp;
		}
		temp = s[i];
		lo = i - 1;
		hi = i + 1;
		while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
			temp = s[lo] + temp + s[hi];
			--lo;
			++hi;
		}
		++lo; --hi;
		if (s[lo] == s[hi] && hi - lo + 1 > Maxl) {
			Maxl = hi - lo + 1;
			ans = temp;
		}
	}
	cout << Maxl << '\n' << ans;

}