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
int dp[40][40][2][2];
vector<int> bit;

int calc(int pos, int cnt, bool equal, bool posi) {
	if(pos == sz(bit) - 1) {
		return (posi && cnt == 0);
	}
	
	if(dp[pos][cnt][equal][posi] != -1) return dp[pos][cnt][equal][posi];
	int res = 0;
	
	for(int next = 0; next <= 1; ++next) {
		if(equal && bit[pos + 1] < next) break;
		
		bool equal1 = (equal && bit[pos + 1] == next);
		bool posi1 = (posi || next);
		
		res += calc(pos + 1, cnt - (next == 0 && posi), equal1, posi1);
	}
	
	return dp[pos][cnt][equal][posi] = res;
}

int main() {
	fast_cin();
	
	while(cin >> n >> k) {
		bit.clear();
		memset(dp, -1, sizeof dp);
		
		while(n) {
			bit.push_back(n&1);
			n /= 2;
		}
		bit.push_back(0);
		reverse(bit.begin(), bit.end());
		long long ans = 0;
		
		for(int cnt = 1; cnt <= sz(bit) - 2; ++cnt) {
			int sum = calc(0, cnt, true, false);
			ans += 1LL*sum*((cnt - 1)/k + 1);
		}
		
		cout << ans << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}