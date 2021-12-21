#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cntc = 0, cnto = 0, cntr = 0, cntn = 0, cnta = 0, res;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'C') cntc++;
		if (s[i] == 'O') cnto++;
		if (s[i] == 'R') cntr++;
		if (s[i] == 'N') cntn++;
		if (s[i] == 'A') cnta++;
	}
	res = min(cntc, cnto / 2);
	res = min(res, cntr);
	res = min(res, cntn);
	res = min(res, cnta);
	cout << res;

}