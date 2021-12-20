/* 
	link problem: 
	Author : vidut_206_CNH
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

string s,s1;


void solve() {
	cin >> s >> s1;
	for(int i=0;i<s.size();++i) {
		if(s[i] == s1[0]) {
			int l=i+1,r = 1;
			while(l < s.size() && r < s1.size() && s[l] == s1[r]) {
				++l;
				++r;
			}
			if(l == s.size()) {
				cout << s.size() + s1.size() - r;
				return;
			}
		}
	}
	cout << s.size() + s1.size();
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}