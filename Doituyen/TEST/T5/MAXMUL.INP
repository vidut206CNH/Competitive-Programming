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
const int MAXN1 = 20;
const int MAXN2 = 1e6+5;

int L, R, X, Y;
int dp[20][20][20][2][2][2];
vector<int> digitL, digitR;

int calc(int pos, int cntX, int cntY, bool equalL, bool equalR, bool posi) {
	
	if(pos == sz(digitR) - 1) {
		return (cntX == 0 && cntY == 0 && posi);
	}
	
	if(dp[pos][cntX][cntY][equalL][equalR][posi] != -1) return dp[pos][cntX][cntY][equalL][equalR][posi];
	
	int res = 0;
	
	for(int num = 0; num <= 9; ++num) {
		if(equalL && num < digitL[pos + 1]) continue;
		if(equalR && num > digitR[pos + 1]) continue;
		
		bool equalL1 = (equalL && digitL[pos + 1] == num);
		bool equalR1 = (equalR && digitR[pos + 1] == num);
		bool posi1 = (posi || num > 0);
		int cntX1 = cntX - (num == X);
		int cntY1 = cntY - (num == Y);
		
		if(X == 0 && posi1 == false) cntX1++;
		if(Y == 0 && posi1 == false) cntY1++;
		
		if(cntX1 < 0 || cntY1 < 0) continue;
		
		res |= calc(pos + 1, cntX1, cntY1, equalL1, equalR1, posi1);
	}
	
	return dp[pos][cntX][cntY][equalL][equalR][posi] = res;
	
}

signed main() {
	fast_cin();
	
	int t;
	cin >> t;
	while(t--) {
		memset(dp, -1, sizeof dp);
		
		digitL.clear();
		digitR.clear();
		
		cin >> L >> R >> X >> Y;
		int tmpL = L, tmpR = R;
		while(tmpL) {
			digitL.push_back(tmpL%10);
			tmpL /= 10;
		}
		
		while(tmpR) {
			digitR.push_back(tmpR%10);
			tmpR /= 10;
		}
		digitR.push_back(0);
		digitL.push_back(0);
		while(sz(digitL) < sz(digitR)) digitL.push_back(0);
		
		reverse(digitL.begin(), digitL.end());
		reverse(digitR.begin(), digitR.end());
		
		int res = 0;
		for(int cX = 0; cX <= 18; ++cX) {
			for(int cY = 0; cY <= 18; ++cY) {
				int ok = calc(0, cX, cY, 1, 1, 0);
				if(ok) res = max(res, cX*cY);
			}
		}
		
		
		cout << res << "\n";
		
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}