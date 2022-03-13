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
const int MAXN1 = 2005;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,k;
int dp[MAXN1][MAXN1];
vector<string> num = {"1110111", "0010010", "1011101", "1011011", "0111010", 
						"1101011", "1101111", "1010010", "1111111", "1111011"};
string a[MAXN1];

int calc(int pos, int rem) {
	if(pos == n + 1) {
		if(rem == 0) return 1;
		else return 0;
	}
	
	if(dp[pos][rem] != -1) return dp[pos][rem];
	
	bool res = 0;
	
	for(int i = 9; i >= 0; --i) {
		string d = num[i];
		bool can = true;
		int sum = 0;
		for(int id = 0; id < 7; ++id) {
			if(d[id] != a[pos][id] && a[pos][id] == '1') {
				can = false;
				break;
			}
			
			if(d[id] != a[pos][id]) {
				sum++;
			}
		}
		
		if(can == false) continue;
		
		if(rem - sum >= 0 && calc(pos + 1, rem - sum)) {
			res = true;
		}
		
	}
	return dp[pos][rem] = res;
	
}

void find(int pos, int rem) {
	if(pos == n) return;
	
	for(int c = 9; c >= 0; --c) {
		string d = num[c];
		bool can = true;
		int sum = 0;
		for(int id = 0; id < 7; ++id) {
			if(d[id] != a[pos + 1][id] && a[pos + 1][id] == '1') {
				can = false;
				break;
			}
			if(d[id] != a[pos + 1][id]) sum++;
		}
		
		if(can == false) continue;
		if(rem - sum >= 0 && calc(pos + 2, rem - sum) == true) {
			cout << c;
			return find(pos + 1, rem - sum);
		}
		
	}
	
	cout << -1;
	return;
}

signed main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	memset(dp, -1, sizeof dp);
	
	
	find(0, k);
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}