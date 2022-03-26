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
const int MAXN1 = 3005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,t;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> t;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	int res = 0;
	
	if(t == 1) {
		for(int i = 1; i <= n; ++i)	{
			int r = i + 1;
			for(int j = i + 1; j <= n; ++j) {
				
				if(r == j) ++r;
				
				while(r <= n && a[r]*a[r] < a[i]*a[i] + a[j]*a[j]) {
					++r;
				}
				res += (r - j - 1);
			}
		}
	}
	
	else if (t == 2) {
		for(int i = 1; i <= n; ++i) {
			int l = i + 1, r = i + 1;
			
			for(int j = i + 1; j <= n; ++j) {
				
				
				if(l == j) ++l;
				if(r == j) ++r;
				
				
				while(l <= n && (a[l]*a[l] < a[i]*a[i] + a[j]*a[j])) ++l;
				while(r <= n && (a[r]*a[r] <= a[i]*a[i] + a[j]*a[j])) ++r;
				
				res += (r - l);
			}
		}
	}
	
	else {
		for(int i = 1; i <= n; ++i) {
			int l = i + 1, r = i + 1;
			
			
			for(int j = i + 1; j <= n; ++j) {
				
				if(l == j) ++l;
				if(r == j) ++r;
				
				while(l <= n && (a[l]*a[l] <= a[i]*a[i] + a[j]*a[j])) ++l;
				while(r <= n && (a[r] < a[i] + a[j])) ++r;
				
				res += (r - l);
			}
		}
	}
	
	
	cout << res;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}