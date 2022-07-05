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
const int N = 70;

long long n,k;
long long dp[70][150][2];
vector<int> digit;
int D;


long long calc(int pos, int sum, int equal) {
	if(pos == sz(digit) - 1) {
		return (sum + D == 0); 
	}
	
	if(dp[pos][sum + N][equal] != -1) return dp[pos][sum + N][equal];
	long long res = 0;
	
	if(sum > -D) res += calc(pos + 1, sum - 1, (equal && digit[pos + 1] == 0));
	if(!(equal && digit[pos + 1]  == 1)) res += calc(pos + 1, sum + 1, (equal && digit[pos + 1] == 0));
	
	return dp[pos][sum + N][equal] = res;
	 
}


long long solve(long long val) {
	digit.clear();
	memset(dp, -1, sizeof dp);
	
	long long tmp = val;
	
	while(tmp) {
		digit.push_back(!(tmp&1));
		tmp >>= 1;
	}
	
	digit.push_back(0);
	reverse(digit.begin(), digit.end());
	D = n - sz(digit) + 1;
	
	long long tot = calc(0, 0, true);
	
	return (val + 1 - tot);
}

int main() {
	fast_cin();
	
	cin >> n >> k;
	
	long long low = 1, high = 1e18, res = 0;
	
	while(low <= high) {
		long long mid = (low + high) >> 1;
		
		if(solve(mid) == k) {
			res = mid;
			break;
		}
		
		if(solve(mid) < k) low = mid + 1;
		else high = mid - 1;
	}
	
	
	for(int i = 1; i <= n; ++i) {
		if((n - i) > 61) cout << "(";
		else cout << ((res >> (n - i) & 1) ? ")" : "(");
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}