// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
using namespace std;

typedef pair<int,int> pii;

const int mxn = 2e5+5;
const int mod = 1e9+7;
const int inf = 2e18;
const double eps = 1e-9;

int t;

signed main() {
	fast_cin();
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int res = 0;
		for(int i=0;i<(int)s.size();++i) {
			if(s[i] == '1') {
				if(i < (int)s.size() - 1 && s[i + 1] == '0') ++i;
				else {
					res++;
				}
			} else {
				if(i < (int)s.size() - 1 && s[i+1] == '1') ++i;
			}
			//cout << res << " " << i << "\t";
		}
		cout << res << "\n";
	}

}