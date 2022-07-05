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
const int MAXN1 = 505;
const int MAXN2 = 1e6+5;
const long long inf = 1e18;


struct task{
	pii X;
	pii Y;
};

int n,S1, S2;
task T[MAXN1];
long long dp[2][MAXN1][MAXN1];

void minimize(long long &X, long long Y) {X = min(X, Y);}

void M(int id) {
	for(int i = 0; i <= S1; i++) {
		for(int j = 0; j <= S2; ++j) dp[id][i][j] = inf;
	}
}

int main() {
	fast_cin();
	
	
	cin >> n >> S1 >> S2;
	for(int i = 1; i <= n; ++i) {
		cin >> T[i].X.fi >> T[i].X.se >> T[i].Y.fi >> T[i].Y.se;
	}
	
	// DP
	M(0);
	M(1);
	
	sort(T + 1, T + n + 1, [&] (const task& A, const task& B){
		return A.X.fi < B.X.fi;
	});
	
	dp[0][0][0] = 0;	
	for(int i = 0; i < n; ++i) {
		for(int sum1 = 0; sum1 <= S1; sum1++) {
			for(int sum2 = 0; sum2 <= S2; ++sum2) {
				long long val = dp[i%2][sum1][sum2];
				if(val == inf) continue;
				
				minimize(dp[(i + 1)%2][sum1][sum2], val);
				
				int nsum1 = sum1 + T[i + 1].X.fi, nsum2;
				nsum2 = (sum2 + (nsum1 >= S1 ? nsum1 - S1 : 0));
					
				nsum1 = min(nsum1, S1);
				nsum2 = min(nsum2, S2);
				if(sum1 != S1) minimize(dp[(i + 1)%2][nsum1][nsum2], val + T[i + 1].X.se);
				

				nsum1 = sum1;
				nsum2 = sum2 + T[i + 1].Y.fi;
				
				nsum1 = min(nsum1, S1);
				nsum2 = min(nsum2, S2);
				
				minimize(dp[(i + 1)%2][nsum1][nsum2], val + T[i + 1].Y.se);
				
			}
		}
		
		M(i%2);
	}
	
	cout << (dp[n%2][S1][S2] == inf ? -1 : dp[n%2][S1][S2]);	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}