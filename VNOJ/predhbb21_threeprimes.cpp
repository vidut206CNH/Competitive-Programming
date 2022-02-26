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
const int MAXN1 = 1e7+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
vector<int> lpf;
vector<int> prime;


bool check(int val) {
	return (val > 1) && (lpf[val] == val);
}


signed main() {
	fast_cin();
	
	lpf.assign(MAXN1, 0);
	
	for(int i = 2; i < MAXN1; ++i) {
		if(lpf[i] == 0) {
			lpf[i] = i;
			prime.push_back(i);
		}
		
		for(auto x : prime) {
			if(x > lpf[i] || x*i >= MAXN1) break;
			lpf[x * i] = x;
		}
	}	
	cin >> n;	
	
	for(auto p : prime) {
		if(check(2*p - 1)) {
			--n;
			if(n == 0) {
				cout << p << " " << p << " " << 2*p - 1;
				exit(0);
			}
		}
		
		if(check(2*p + 1)) {
			--n;
			if(n == 0) {
				cout << p << " " << p << " " << 2*p + 1;
				exit(0);
			}
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}