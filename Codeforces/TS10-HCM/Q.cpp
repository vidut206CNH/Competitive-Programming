#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,t,cnt=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size()-2;++i) {
		x = s[i]+s[i+2]-96;
		t = s[i+1]-48;
		if(x==t&&s[i]!=48) cnt++;
	}
	cout << cnt;
}