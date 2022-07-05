/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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
string s;
int h,m;

bool check(int X, int Y) {
	vector<int> p;
	p.push_back(X/10);
	p.push_back(X%10);
	p.push_back(Y/10);
	p.push_back(Y%10);
	
	return (p[0] == p[3] && p[1] == p[2]);
}

int main() {
	fast_cin();
	
	
	cin >> s;
	h = (s[0] - '0')*10 + s[1] - '0';
	m = (s[3] - '0')*10 + s[4] - '0';
	int cnt = 0;
	
	if(check(h,m)) {
		cout << cnt;
		exit(0);
	}
	while(true) {
		
		cnt++;
		m = m + 1;
		if(m == 60) {
			m = 0;
			h += 1;
		}
		if(h == 24) {
			h = 0;
		}
		
		if(check(h,m)) {
			cout << cnt;
			break;
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}