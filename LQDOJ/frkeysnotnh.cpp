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

long long n;

int main() {
	fast_cin();
	long long res = 1;
	cin >> n;
	for(int i = 2; 1LL*i*i <= n; ++i) {
		if(n%i) continue;
		
		int cnt = 0;
		while(n%i == 0) {
			cnt++;
			n /= i;
		}
		cnt += 2;
		
		res = res*(1LL*cnt*(cnt - 1)/2);
	}
	
	if(n > 1) {
		res = res*3;
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}