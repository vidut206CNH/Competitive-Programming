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

long long A,B;
vector<int> digitA,digitB;
long long dp[10][10][2][2][2];
long long cnt[10][10][10][2][2][2];


long long calc(int pos, int num, bool equalA, bool equalB, bool posi) {
	if(pos == sz(digitA) - 1) {
		if(posi) cnt[num][pos][num][equalA][equalB][posi] = 1;
		return (posi);
	}
	
	if(dp[pos][num][equalA][equalB][posi] != -1) {
		return dp[pos][num][equalA][equalB][posi];
	}
	
	long long res = 0;
	
	for(int next = 0; next <= 9; ++next) {
		if(equalA && next < digitA[pos + 1]) continue;
		if(equalB && next > digitB[pos + 1]) continue;
		
		bool equalA1 = (equalA && next == digitA[pos + 1]);
		bool equalB1 = (equalB && next == digitB[pos + 1]);
		bool posi1 = (posi || next);
		
		res += calc(pos + 1, next, equalA1, equalB1, posi1);
		
		for(int j = 0; j <= 9; ++j) {
			cnt[j][pos][num][equalA][equalB][posi] += cnt[j][pos + 1][next][equalA1][equalB1][posi1];
		}
		
	}
	
	if(posi) cnt[num][pos][num][equalA][equalB][posi] += res;
	return dp[pos][num][equalA][equalB][posi] = res;
}

int main() {
	fast_cin();
	
	while(cin >> A >> B) {
		if(A == 0 && B == 0) break;
		digitA.clear();
		digitB.clear();
		memset(cnt, 0, sizeof cnt);
		memset(dp, -1, sizeof dp);
		
		if(A > B) swap(A, B);
		while(A) {
			digitA.push_back(A%10);
			A /= 10;
		}
		while(B) {
			digitB.push_back(B%10);
			B /= 10;
		}
		
		digitB.push_back(0);
		while(sz(digitA) < sz(digitB)) digitA.push_back(0);
		reverse(digitA.begin(), digitA.end());
		reverse(digitB.begin(), digitB.end());
		
		
		calc(0, 0, 1, 1, 0);
		
		for(int i = 0; i <= 9; ++i) {
			cout << cnt[i][0][0][1][1][0] << " \n"[i == 9];
		}
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
