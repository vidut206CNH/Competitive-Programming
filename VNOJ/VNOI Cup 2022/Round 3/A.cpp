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

int n,q;

bool Try(int X, int Y) {
	if((X + Y)%2) return false;
	int a = (X + Y)/2;
	int b = (X - Y)/2;
	if(a >= 1 && a <= n && b >= 1 && b <= n) {
		cout << a << " " << b << "\n";
		return true;
	}
	return false;
}


int main() {
	fast_cin();
	
	cin >> n >> q;
	while(q--) {
		int x,y,s,t;
		cin >> x >> y >> s >> t;
		if((x + y)%2 != (s + t)%2) {
			cout << -1 << "\n";
			continue;
		}
		
		if(x == s && y == t) {
			cout << 0 << "\n";
			continue;
		}
		
		if(abs(x - s) == abs(y - t)) {
			cout << 1 << "\n";
			cout << s << " " << t << "\n";
			continue;
		}
		else {
			cout << 2 << "\n";
			if(Try(x + y, s - t)) {
				cout << s << " " << t << "\n";
				continue;
			}
			if(Try(x - y, s - t)) {
				cout << s << " " << t << "\n";
				continue;
			}
			
			if(Try(x - y, s + t)) {
				cout << s << " " << t << "\n";
				continue;
			}
			
			if(Try(x + y, s + t)) {
				cout << s << " " << t << "\n";
				continue;
			}
			//
			if(Try(s + t, x - y)) {
				cout << s << " " << t << "\n";
				continue;
			}
			if(Try(s - t, x - y)) {
				cout << s << " " << t << "\n";
				continue;
			}
			
			if(Try(s - t, x + y)) {
				cout << s << " " << t << "\n";
				continue;
			}
			
			if(Try(s + t, x + y)) {
				cout << s << " " << t << "\n";
				continue;
			}
		}
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}