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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];



void sub3() {
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		int minn = a[i], maxx = a[i];
		for(int j = i; j >= 1; --j) {
			minn = min(minn, a[j]);
			maxx = max(maxx, a[j]);
			if((minn == a[j] && maxx == a[i]) ||( maxx == a[j] && minn == a[i])) res++;
		}
	}
	
	cout << res;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	bool incre = true, decre = true;	
	for(int i = 1; i < n; ++i) {
		incre &= (a[i] < a[i + 1]);
		decre &= (a[i] > a[i + 1]);
	}
	
	if(incre || decre) {
		cout << (n + 1)*n/2;
		exit(0);
	}
	
	
	sub3();
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}