#include <bits/stdc++.h>

using namespace std;

int cvs(string s) {
	int res = 0,x;
	for(int i=0;i<s.size();++i) {
		x = (int)s[i] - 48;
		res *= 10;
		res += x;
	}
	return res;
}

int main() {
	int ans,t,m;
	cin >> ans;
	string s;
	cin >> s;
	m = pow(10,s.size());
	ans = ans*m + cvs(s);
	t = ans/__gcd(ans,m);
	m = m/__gcd(ans,m);
	cout << t << ' ' << m;
}