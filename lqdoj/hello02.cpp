#include<bits/stdc++.h>

using namespace std;

void solve(string s) {
    string s1;cin >> s1;
	int i=0,j=0;
	while(i<s1.size()) {
		if(s1[i]==s[j]) {
            if(j==s.size()-1) {
                cout << "YES" << "\n";
                return;
            }
            ++j;
		}
		++i;
	}
	cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin >> n;
	string s;
	cin >> s;
	while(n) {
		solve(s);
		--n;
	}
}
