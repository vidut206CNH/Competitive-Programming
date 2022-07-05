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
const int MAXN2 = 1e6+15;
const int MAXX = (1 << 18);

int n,q;
string s;
vector<vector<int>> D[MAXN2];
int segt[(MAXX << 1) + 5][30];

void update(const vector<int> &X) {
	int p = X[0];
	int x = X[1];
	int y = X[2];
	
	segt[p += MAXX][x] = y;
	for(p >>= 1; p; p >>= 1) {
		int ls = p << 1, rs = ls | 1;
		for(int i = 0; i < 26; ++i) {
			segt[p][i] = segt[rs][segt[ls][i]];
		}
	}
	
}

int main() {
	fast_cin();
	
	cin >> s;
	n = sz(s);
	
	for(int i = 1; i < (MAXX << 1) + 5; ++i) {
		for(int j = 0; j < 26; ++j) {
			segt[i][j] = j;
		}
	}
	
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		int l,r;
		char x,y;
		cin >> l >> r >> x >> y;
		D[l].push_back({i, x - 'a', y - 'a'});
		D[r + 1].push_back({i, x - 'a', x - 'a'});
	}
	
	for(int i = 0; i < n; ++i) {
		for(auto X : D[i]) {
			update(X);
		}
		
		cout << char(segt[1][s[i] - 'a'] + 'a');
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}