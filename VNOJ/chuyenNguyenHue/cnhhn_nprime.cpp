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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+20;
const int inf = 1e18;

vector<int> lpf(MAXN2,0);
vector<int> p;
int n;


signed main() {
	fast_cin();
//	linear sieve
	lpf[0] = lpf[1] = -1;
	
	for(int i=2;i<MAXN2;++i) {
		if(lpf[i] == 0) {
			lpf[i] = i;
			p.push_back(i);
		}
		for(auto x : p) {
			if(x*i >= MAXN2 || x > lpf[i]) break;
			lpf[i*x] = 	x;
		}	
	}
//	eratothenes sieve
/*
	for(int i=2;i*i<MAXN2;++i) {
		if(!lpf[i]) {
			lpf[i] = i;
			for(int j=i*i;j < MAXN2;j += i) {
				if(lpf[j] == 0) lpf[j] = i;
			}
		}
	}
*/	
//	for(int i=2;i<MAXN2;++i) if(lpf[i] == i) db(i);
	
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		//db(lpf[x]);
		if((lpf[x] == x) || (lpf[x-1] == x-1) || (lpf[x+1] == x+1)) cout << "1\n";
		else cout << "0\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}