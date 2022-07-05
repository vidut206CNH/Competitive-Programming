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

int m,n;
int a[105][105];
vector<pii> res;

void Row(int x) {
	int minn = MAXN1;
	
	for(int i = 1; i <= n; ++i) {
		minn = min(minn, a[x][i]);
	}
	
	for(int i = 1; i <= minn; ++i) res.push_back({0, x});
	
	for(int i = 1; i <= n; ++i) {
		a[x][i] -= minn;
	}
	
}


void Col(int x) {
	int minn = MAXN1;
	for(int i = 1; i <= m; ++i) {
		minn = min(minn, a[i][x]);
	}
	
	for(int i = 1; i <= minn; ++i) res.push_back({1, x});
	
	for(int i = 1; i <= m; ++i) {
		a[i][x] -= minn;
	}
}

int main() {
	fast_cin();
	
	
	cin >> m >> n;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	if(m > n) {
		for(int i = 1; i <= n; ++i) Col(i);
		for(int i = 1; i <= m; ++i) Row(i);
	}
	
	else {
		for(int i = 1; i <= m; ++i) Row(i);
		for(int i = 1; i <= n; ++i) Col(i);
	}
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(a[i][j]) {
				cout << -1;
				exit(0);
			}
		}
	}
	
	cout << sz(res) << "\n";
	
	for(auto x : res) {
		cout << (x.fi == 0 ? "row " : "col ") << x.se << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}