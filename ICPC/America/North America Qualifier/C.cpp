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

bool ispri[105];
vector<int> prime;

signed main() {
	fast_cin();
	memset(ispri, true, sizeof ispri);
	
	for(int i=2;i <= 100;++i) {
		if(ispri[i]) {
			prime.push_back(i);
			for(int j=i*i;j <= 100; j += i) ispri[j] = false;
		}	
	}
	int n;
	cin >> n;
	int prod = 1;
	for(int i=0;i<sz(prime);++i) {
		if(n/prime[i] < prod) {
			int g = 1;
			for(int j=0;j < i;++j) g *= (prime[j] - 1);
			int f = prod - g;
			int d = prod;
			int temp = gcd(f,d);
			f /= temp;
			d /= temp;
			cout << f << "/" << d;
			exit(0); 
		}
		prod *= prime[i];
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}