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
int a[MAXN2];

int solve(int val) {
	int sum = 0, r = 1;
	int res = 0;
	while(r <= n) {
		if(sum + a[r] == val) {
			res++;
			++r;
			sum = 0;
		}
		else if(sum + a[r] > val) {
			res = -1;
			break;
		}
		
		else {
			sum += a[r];
			++r;
		}
	}
	if(sum != 0) res = -1;
	
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	int res = 1;
	for(int i = 1; i*i <= sum; ++i) {
		if(sum%i) continue;
		int s1 = solve(i);
		int s2 = solve(sum/i);
		
		if(s1 != -1) res = max(res, s1);
		if(s2 != -1) res = max(res, s2);
	}
	
	cout << res;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}