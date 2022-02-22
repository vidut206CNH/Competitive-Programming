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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int cnt[MAXN2];

vector<int> p = {1, 11, 111, 1111, 11111, 111111, 1111111};
vector<int> g = {1, 2, 3, 4, 5, 6, 7, 8, 9};

signed main() {
	fast_cin();
	
	
	cin >> n;
	int res = 0;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		for(auto x : p) {
			for(auto y : g) {
				if(x*y < a[i]) continue;
				if(x*y - a[i] >= MAXN2) continue;
				res += cnt[x*y - a[i]];			
			}
		}
		cnt[a[i]]++;
	}
	
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}