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

struct state{
	pii left, mid, right;
};

pii add(const pii& A, const pii& B) {
	return {A.fi + B.fi, A.se + B.se};
}

signed main() {
	fast_cin();
	
	int p,q;
	while(cin >> p >> q) {
		if(p == 1 && q == 1) break;
		state cur = {{0, 1}, {1, 1}, {1, 0}};
		
		while(cur.mid.fi*q != cur.mid.se*p) {
			state next;
			if(cur.mid.fi*q > cur.mid.se*p) {
				next.mid = add(cur.left, cur.mid);
				next.left = cur.left;
				next.right = cur.mid;
				cout << 'L';
			}
			
			else {
				next.mid = add(cur.mid, cur.right);
				next.left  =cur.mid;
				next.right = cur.right;
				cout << 'R';
			}
			cur = next;
		}
		cout << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}