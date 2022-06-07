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

int r,c;
int a[30];
int b[30];
int dx[] = {0, 0, -1, 1, 0};
int dy[] = {1, -1, 0, 0, 0};



int main() {
	fast_cin();
	
/*	freopen("billboard.inp", "r", stdin);
	freopen("billboard.out", "w", stdout);*/
	
	cin >> r >> c;
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			char ca;
			cin >> ca;
			a[i] += (ca == 'X' ? (1 << j) : 0);
		}
	}
	
	int res = 1e9;
	
	for(int mask = 0; mask < (1 << c); ++mask) {
		for(int i = 0; i < r; ++i) b[i] = a[i];
		
		int cnt = 0;
		b[0] ^= (mask^(mask << 1)^(mask >> 1));
		b[1] ^= mask;
		b[1] &= ((1 << c) - 1);
		b[0] &= ((1 << c) - 1);
		cnt += __builtin_popcount(mask);
		
		for(int i = 1; i < r; ++i) {
			int pre = b[i - 1];
			
			b[i - 1] ^= pre;
			b[i + 1] ^= pre;
			b[i] ^= (pre^(pre << 1)^(pre >> 1));
			b[i] &= ((1 << c) - 1);
			cnt += __builtin_popcount(pre);
		}
		
		
		if(b[r - 1] == 0) {
			
			res = min(res, cnt);
		}
	}
	
	if(res == (int)1e9) {
		cout << "Damaged billboard.";
	}
	
	else cout << "You have to tap " << res << " tiles.";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}