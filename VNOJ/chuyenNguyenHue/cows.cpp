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

int n,k;
int a[MAXN1];
int L_min[MAXN1], L_max[MAXN1];
int R_min[MAXN1], R_max[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n >> k;	
	
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	
 	// L_min, L_max: L_max[i] = j xa nhat sao cho a[i] + k >= a[j]
 	for(int i = 1; i <= n; ++i) {
 		L_min[i] = i;
 		L_max[i] = i;
 		int id = i - 1;
 		while(id > 0 && a[i] + k >= a[id]) {
 			L_max[i] = L_max[id];
 			id = L_max[id] - 1;
 		}
 		id = i - 1;
 		while(id > 0 && a[i] - k <= a[id]) {
 			L_min[i] = L_min[id];
 			id = L_min[id] - 1;
 		}
 		db(L_min[i]);
 		db(L_max[i]);
 		cerr << "\n";
 	}
 	
 	// find R_min, R_max:
 	
 	for(int i = n; i >= 1; --i) {
 		R_min[i] = i;
 		R_max[i] = i;
 		int id = i + 1;
 		while(id <= n && a[i] + k >= a[id]) {
 			R_max[i] = R_max[id];
 			id = R_max[id] + 1;
 		}
 		
 		id = n + 1;
 		while(id <= n && a[i] - k <= a[id]) {
 			R_min[i] = R_min[id];
 			id = R_min[id] + 1;
 		}
 	}
 	
 	for(int i = 1; i <= n; ++i) {
 		int l = i - max(L_min[i], L_max[i]);
 		int r = min(R_min[i], R_max[i]) - i;
 		cout << l + r + 1 << " ";
 	}
 	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}