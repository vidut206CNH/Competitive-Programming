#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	string s,str;
	cin >> s;
	str = s;
	while(m) {
		for(int i=s.size()-1;i>=n;--i) {
			str  = s[i] + str;
		}
		s = str;
		--m;
	}
	cout << s;
}