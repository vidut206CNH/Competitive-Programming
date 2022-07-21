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

long long  a,b,c;

int main() {
	fast_cin();
	
	cin >> a >> b >> c;
	if(b < c) swap(b,c);
	if(a < b) swap(a, b);
	
	long long low = 0, high = min({a, b, c}), res = -1;
	
	while(low <= high) {
		long long mid = (low + high) >> 1;
		long long na = a - mid;
		long long nb = b - mid;
		long long nc = c - mid;
		if(na == nb + nc) {
			res = mid + na;
			break;
		}
		if(na > nb + nc) high = mid - 1;
		else low = mid + 1;
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}