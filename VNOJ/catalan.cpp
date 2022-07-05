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

int n;
int a[50];
long long dp[50][50];
long long k;

long long calc(int pos, int cur) {
	if(pos == 2*n + 1) {
		return (cur == 0);
	}
	
	if(dp[pos][cur] != -1) return dp[pos][cur];
		
	long long res = 0;
	if(cur) {
		res += calc(pos + 1, cur - 1);	
	}
	
	if(cur + 1 <= 2*n - pos) {
		res += calc(pos + 1, cur + 1);
	}
	
	return dp[pos][cur] = res;
}

int main() {
	fast_cin();
	
	memset(dp, -1, sizeof dp);
	
	cin >> n;
	for(int i = 1; i <= 2*n + 1; ++i) {
		cin >> a[i];
	}
	
	cin >> k;
	long long res = 0;
	
	for(int i = 1; i < 2*n + 1; ++i) {
		
		if(a[i + 1] == a[i] + 1 && a[i]) {
			res += calc(i + 1, a[i] - 1);
		}
		
	}
	
	cout << res + 1 << "\n";
	int cur = 0;
	for(int i = 1; i <= 2*n + 1; ++i) {
		cout << cur << " ";
		if(i == 2*n + 1) break;
		
		if(cur && k > calc(i + 1, cur - 1)) {
			k -= calc(i + 1, cur - 1);
			cur++;
		}
		
		else if(cur) cur--;
		else cur++;
	}


	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}