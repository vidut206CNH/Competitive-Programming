/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

struct Q{
	int a,b,c;
};

Q p[2];

bool check(int id) {
	if(p[id].a == p[id].b && p[id].a == 0) {
		return (p[id].c);
	}
	
	return p[id].c%__gcd(p[id].a, p[id].b);
}


int main() {
	fast_cin();
	
	freopen("INTSLE.INP", "r", stdin);
	freopen("INTSLE.OUT", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {	
		for(int i = 0; i < 2; ++i) cin >> p[i].a >> p[i].b >> p[i].c;
		long long D, Dx, Dy;
		D = 1LL*p[0].a*p[1].b - 1LL*p[0].b*p[1].a;
		Dx = 1LL*p[0].c*p[1].b - 1LL*p[0].b*p[1].c;
		Dy = 1LL*p[1].c*p[0].a - 1LL*p[0].c*p[1].a;
		
		if(D == 0) {
			if(Dx || Dy) {
				cout << "NO SOLUTION";
			}
			else if(Dx == Dy) {
				if(check(0)  || check(1)) cout << "NO SOLUTION";
				else cout << "INFINITE";
			}
		}
		
		else {
			if(Dx%D == 0 && Dy%D == 0) {
				cout << Dx/D << " " << Dy/D;
			}
			else cout << "NO SOLUTION";
		}
		
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}