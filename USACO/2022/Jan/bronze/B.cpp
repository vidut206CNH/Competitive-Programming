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

int t;
int a[4];
int b[4];
int c[4];
bool found = 0;

bool check(int A[], int B[]) {
	int win = 0, tie = 0;
	for(int i=0;i<4;++i) {
		for(int j=0;j<4;++j) {
			win += (A[i] > B[j]);
			tie += (A[i] == B[j]);
		}
	}
	
	return (win > 16 - win - tie);
}

void func(int pos) {
	if(found) return;
	if(pos == 4) {
		int wa = 0,wb = 0,wc = 0;
		wa += check(a,b);
		wa += check(a,c);
		wb += check(b,a);
		wb += check(b,c);
		wc += check(c, a);
		wc += check(c, b);
		if(wa == wb && wb == wc && wa == 1) found = true;
		return;
	}
	
	for(int i=1;i<=10;++i) {
		c[pos] = i;
		func(pos+1);
	}
	
	
}

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		found = false;
		for(int i=0;i<4;++i) cin >> a[i];
		for(int i=0;i<4;++i) cin >> b[i];
		func(0);
		cout << (found ? "yes\n" : "no\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}