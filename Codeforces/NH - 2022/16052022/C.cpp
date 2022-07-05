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
const double eps = 1e-9;

int n,C;
long long cnt[MAXN2];
long long f[2*MAXN2];



int main() {
	fast_cin();
	
	cin >> n >> C;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	
	for(int i = 0; i < 2*C; ++i) {
		f[i] = cnt[i%C];
		if(i > 0) f[i] += f[i - 1];
	}
	
	int best = 0;
	
	long long res = 0;
	
	for(int i = 0; i < C; ++i) {
		best = i + C/2;
		
		long long x = f[best] - f[i];
		
		res += 1LL*x*(x - 1)/2*cnt[i];
		res += 1LL*(cnt[i])*(cnt[i] - 1)/2*x;
		res += 1LL*cnt[i]*(cnt[i] - 1)*(cnt[i] - 2)/6;
		
		if(best < C && (best - i)*2 == C) {
			res -= 1LL*(cnt[i])*(cnt[i] - 1)/2*cnt[best];
			res -= 1LL*(cnt[best])*(cnt[best] - 1)/2*cnt[i];
			 
		}
		
	}
	
	cout << (1LL*n*(n - 1)*(n - 2)/6) - res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}