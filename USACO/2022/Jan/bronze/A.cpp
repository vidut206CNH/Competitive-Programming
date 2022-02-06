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

char a[3][3];
char ans[3][3];

int cnta[305];
int cntans[305];

signed main() {
	fast_cin();
	for(int i=0;i<3;++i) {
		for(int j=0;j<3;++j) {
			cin >> a[i][j];
			cnta[a[i][j]]++;
		}
	}
	int green = 0, yellow = 0;
	
	for(int i=0;i<3;++i) {
		for(int j=0;j<3;++j) {
			cin >> ans[i][j];
			if(ans[i][j] != a[i][j]) cntans[ans[i][j]]++;
			else {
				cnta[a[i][j]]--;
				green++;
			}
		}
	}
	
	for(int i = (int)'A'; i <= (int)'Z'; ++i) {
		yellow += min(cnta[i], cntans[i]);
	}
	
	cout << green << "\n" << yellow;
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}