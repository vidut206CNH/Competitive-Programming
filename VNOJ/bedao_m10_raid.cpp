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
const int MAXN2 = 1e9;
const int inf = 1e18;

int n;
int a[MAXN1];
int f[MAXN1];
int minn[MAXN1];

signed main() {
	fast_cin();
	
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] *= MAXN2;
	}
	
	int low = 1, high = 1e15;
	int res = 0;
	
	while(low <= high) {
		int mid = (low + high) >> 1;
		
		for(int i = 1; i <= n; ++i) {
			f[i] = f[i - 1] + a[i] - mid;
			
			if(i == 1) minn[i] = f[i];
			else minn[i] = min(minn[i - 1], f[i]);
		}
		
		int sum = inf;
		for(int i = 2; i < n; ++i) {
			sum = min(sum, f[n] - f[i] + minn[i - 1]);
		}
/*		db(sum);
		db(mid);
		cerr << "\n";*/
		
		if(0 <= sum && sum <= 9) {
			res = mid;
			break;
		}
	
		if(sum < 0) high = mid - 1;
		else low = mid + 1;
	}
	
	
	cout << fixed << setprecision(3) << 1.0*(res/1000000)/1000;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}