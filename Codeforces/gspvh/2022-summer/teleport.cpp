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
const long long inf = 1e18;

int n;
int pos[MAXN1];
long long f[MAXN1];
int p[MAXN1];
int numPos;
long long sumNeg;

long long solve() {
	numPos = 0;
	sumNeg = 0;
	
	for(int i = 1; i <= n; ++i) {
		if(pos[i] <= 0) sumNeg += -pos[i];
		else p[++numPos] = pos[i];
	}
	
	if(numPos == 0) return sumNeg;
	sort(p + 1, p + numPos + 1);
	
	for(int i = 1; i <= numPos; ++i) f[i] = f[i - 1] + p[i];
	
	long long res = inf;
	for(int i = 0; i < numPos; ++i) {
		int t = (numPos - i)/2;
		res = min(res, f[i] + f[numPos] - f[numPos - t] - (f[i + t] - f[i]));
	}
	
	return res + sumNeg;
}


int main() {
	fast_cin();
	
/*	freopen("teleport.inp", "r", stdin);
	freopen("teleport.out", "w", stdout);*/
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> pos[i];
	}
	
	long long ans = inf;
	ans = min(ans, solve());
	
	for(int i = 1; i <= n; ++i) pos[i] *= -1;
	
	ans = min(ans, solve());
	
	cout << ans;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}