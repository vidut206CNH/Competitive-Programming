#include<bits/stdc++.h>

using namespace std;


long long powz(long long a,long long b) {
	long long res = 1;
	for(int i=1;i<=b;++i) {
		res *= a;
	}
	return res;
}

int main() {
	string s;
	cin >> s;
	long long cnt1=0,a=0,b,cnt2,res,m;
	for(int i=0;i<s.size();++i) {
		if(s[i]!='.') {
			a *= 10;
			a = a+(s[i]-48);
			cnt1++;
		}
		else {
			b = a;
			a = 0;
			cnt2 = s.size()-cnt1-1;
		}
	}
	m = powz(10,cnt2);
	res = b*powz(10,cnt2) + a;
	m = m/__gcd(res,m);
	res = res/__gcd(res,powz(10,cnt2));
	cout << res << ' ' << m;
	
}