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

string s;

signed main() {
	fast_cin();
	
	deque<char> d;
	char c;
	while(cin >> c) {
		d.push_back(c);
	}
	
	while(d.size() > 2 && d.back() == d.front() && d.front() == 'a') {
		d.pop_back();
		d.pop_front();
	}
	
	while(!d.empty() && d.back() == 'a') d.pop_back();
	
	while(!d.empty()) {
		if(d.size() == 1) {
			cout << "Yes";
			exit(0);
		}
		
		if(d.front() != d.back()) {
			cout << "No";
			exit(0);
		}
		d.pop_back();
		d.pop_front();
	}
	
	cout << "Yes";
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}