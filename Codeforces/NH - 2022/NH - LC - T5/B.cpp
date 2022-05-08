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
const int MAXN1 = 1e5+55;
const int MAXN2 = 2e6+55;
const int inf = 1e18;

int n, na, nb, nc;
char a[MAXN2];
int pa[MAXN2];
int pb[MAXN2];
int pc[MAXN2];

signed main() {
	fast_cin();
	n = 1;
	while(cin >> a[n]) {
		++n;
	}
	
	--n;
	
	for(int i = n + 1; i <= 2*n; ++i) {
		a[i] = a[i - n];
		na += (a[i] == 'A');
		nb += (a[i] == 'B');
		nc += (a[i] == 'C');
	}
	
	for(int i = 1; i <= 2*n; ++i) {
		pa[i] = pa[i - 1] + (a[i] == 'A');
		pb[i] = pb[i - 1] + (a[i] == 'B');
		pc[i] = pc[i - 1] + (a[i] == 'C');
	}
	
	int res = MOD;
	
	for(int i = 1; i <= n; ++i) {
		int X = pb[i + na - 1] - pb[i - 1];
		int Y = pa[i + na + nb - 1] - pa[i + na - 1];
		int sA = na - pa[i + na - 1] + pa[i - 1];
		int sB = nb - (pb[i + na + nb - 1] - pb[i + na - 1] + min(X,Y));
		
		res = min(res, sA + sB);
	}
	
	
	for(int i = 1; i <= n; ++i) {
		int X = pc[i + na - 1] - pc[i - 1];
		int Y = pa[i + na + nc - 1] - pa[i + na - 1];
		
		int sA = na - pa[i + na - 1] + pa[i - 1];
		int sC = nc - (pc[i + na + nc - 1] - pc[i + na - 1] + min(X, Y));
		res = min(res, sA + sC);
	}
	
	cout << res;
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}