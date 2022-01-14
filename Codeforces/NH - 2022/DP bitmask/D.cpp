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

int n;
int a[6][MAXN1];
/*
state:
00: left
01: up
10: down
11: right
*/

bool check(int i, int state) {
	if(((state >> 4) & ((1 << 2) - 1)) == 3) return false;
	if((state & ((1 << 2) - 1)) == 0) return false;
	if(i == 1) {
		for(int i=0;i<5;i += 2) {
			if((state >> i & 1) && !(state >> (i+1) & 1)) return false;
		}
	}
	if(i == n) {
		for(int i=1;i<=5;i+=2) {
			if((state >> i & 1) && !(state >> (i-1) & 1)) return false;
		}
	}
	return true;
}


void optimize(int i, int state, int pre) {
	
}

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i=1;i<=n;++i) {
		for(state=0;state < (1LL << 6); ++state) {
			if(check(state)) {
				for(int pre=0;pre < (1 << 6); ++pre) {
					optimize(i,state,pre);
				}			
			}
		}
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}