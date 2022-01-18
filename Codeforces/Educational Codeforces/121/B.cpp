/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t;


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		string s;
		
		cin >> s;
		string res = "";
		reverse(s.begin(),s.end());
		bool found = 0;
		for(int i=0;i<sz(s)-1;++i) {
			if(s[i] + s[i+1] - '0' >= 10 + '0') {
				int d = s[i] - '0';
				int g = s[i+1] - '0';
				d += g;
				res += (char)(d%10 + '0');
				if(d >= 10) res += (char)(d/10 + '0');
				for(int j=i+2;j<sz(s);++j) res += s[j];
				found = 1;
				break;
			}
			res += s[i];
		}
		
		if(!found) {
			res = "";
			for(int i=sz(s)-1;i>0;--i) {
				if(s[i-1] != '0') {
					char d = char(s[i] + s[i-1] - '0');
					res = d + res;
					for(int j=i-2;j>=0;--j) res =  s[j] + res;
					break;
				}
				if(i==1) {
					char d = (s[i] + s[i-1] - '0');
					res = d + res;
					break;
				}
				res = s[i] + res;
			}
		}
		while(res.size() > 1 && res.back() == '0') res.erase(res.end() - 1);
		reverse(res.begin(),res.end());
		cout <<  res << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}