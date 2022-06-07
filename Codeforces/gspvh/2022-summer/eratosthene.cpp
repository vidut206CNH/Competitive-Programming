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
const int MAXN2 = 5e6+5;

long long l,r;
bool p[MAXN2];
vector<int> prime;
bool bad[MAXN2];

int main() {
	fast_cin();
	
/*	freopen("eratosthene.inp", "r", stdin);
	freopen("eratosthene.out", "w", stdout);*/
	
	cin >> l >> r;
	
	memset(p, true, sizeof p);
	
	for(int i = 2; 1LL*i*i <= r; ++i) {
		if(p[i]) {
			for(long long j = 1LL*i*i; j <= r/j; j += i) {
				p[j] = false;
			}
		}
	}
	for(int i = 2; 1LL*i*i <= r; ++i) {
		if(p[i]) prime.push_back(i);
	}
	
	
	for(auto x : prime) {
		long long L = max(1LL*(l + x - 1)/x, 2LL);
		long long R = 1LL*r/x;
		
		while(L <= R) {
			bad[1LL*L*x - l] = true;
			++L;
		} 
	}
	
	if(l == 1) {
		bad[0] = true;
	}
	int cnt = 0;
	for(int i = 0; i <= r - l; ++i) {
		cnt += !bad[i];
	}
	
	cout << cnt;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}