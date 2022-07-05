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

int h[3];
int w[3];
int X[3][3];
int sumr[3];
int sumc[3];
long long res = 0;

void f(int row) {
	if(row == 2) {
		
		bool good = true;
		int sum = 0;
		
		for(int c = 0; c < 3; ++c) {
			good &= (w[c] > sumc[c]);
			sum += (w[c] - sumc[c]);
		}
		
		res += (good && sum == h[2]);
		return;
	}
	
	else {
		for(int val = 1; val < h[row]; ++val) {
			sumc[0] += val;
			X[row][0] = val;
			
			for(int val1 = 1; val1 < h[row] - val; ++val1) {
				sumc[1] += val1;
				sumc[2] += (h[row] - val - val1);
				
				f(row + 1);
				
				sumc[1] -= val1;
				sumc[2] -= (h[row] - val - val1);
			}
			
			sumc[0] -= val;
		}
	}
}


int main() {
	fast_cin();
	
	for(int i = 0; i < 3; ++i) cin >> h[i];
	for(int i = 0; i < 3; ++i) cin >> w[i];
	f(0);
		
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}