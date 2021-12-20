#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;cin >>n;
	string s;cin >> s;
	int cnt1=0,cnt2=0;
	vector<int> a(150,0);
	for(int i=0;i<n;++i) {
		a[s[i]]++;
		if(a[s[i]]>1) {
			cnt1++;
		}
	}
	for(int i='a';i<='z';++i) {
		if(a[i]==0) cnt2++;
	}
	if(cnt1>cnt2) cout << -1;
	else cout << cnt1;

}