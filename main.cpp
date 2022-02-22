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

int cnt[10];

signed main() {
	fast_cin();
	int res = 0;
	for(int i = 100; i <= 999; ++i) {
		memset(cnt, 0, sizeof cnt);
		int tmp = i;
		while(tmp) {
			cnt[tmp%10]++;
			tmp /= 10;
		}
		
		int sum = 0,g = 0;
		bool bad = false;
		for(int j = 0; j <= 5; ++j) {
			if(cnt[j] > 1) bad = true;
			sum += cnt[j];
			if(cnt[j]) g += j;
		}
		
		bad |= (sum != 3);
		
		if(!bad && g%3 != 0) {
			cout << i << "\n";
			res++;
		} 
	}
	
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}