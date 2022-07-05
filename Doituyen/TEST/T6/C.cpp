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

int n,k;
int a[MAXN1];
vector<pii> C[MAXN1];
int main() {
	
	freopen("PT.INP", "r", stdin);
	freopen("PT.OUT", "w", stdout);
	
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n;) {
		int id = i;
		while(id <= n && a[id] == a[i]) ++id;
		
		C[a[i]].push_back({i, id - 1});
		
		i = id;
	}
	
	int color = -1, best = 0;
	
	for(int i = 1; i <= k; ++i) {
		int sum = 0;
		for(auto X : C[i]) {
			int L = X.fi - 1;
			int R = X.se + 1;
			sum++;
			
			sum += (L >= 1 && R <= n && a[L] == a[R]);
		}
		
		if(best < sum) {
			best  = sum;
			color = i;
		}
	}
	
	cout << color;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}