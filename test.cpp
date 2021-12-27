/*
	Author : vidut_206_CNH
	Link problem: 
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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;


string s;


signed main() {
	fast_cin();
	
	cin >> s;
	reverse(s.begin(),s.end());
	
	vector<string> p;
	
	for(int i=0;i < sz(s); ++i) {
		
		for(int j=i+1;j<sz(s);++j) {
			
			if(s[i] < s[j]) {
				string tmp = s;
				swap(tmp[i], tmp[j]);
				p.push_back(tmp);
				break;
			}
			
		}
		
	}
	
	
	if(sz(p) == 0) cout << 0;
	
	else {
		string res = p[0];
		for(int i=0;i < sz(p);++i) {
			
			for(int pos=sz(s)-1; pos >= 0; --pos) {
				
				if(res[pos] < p[i][pos]) {
					res = p[i];
					break;
				}
				
			}
			
		}
		
		reverse(res.begin(), res.end());
		cout <<res;
	}
	
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
