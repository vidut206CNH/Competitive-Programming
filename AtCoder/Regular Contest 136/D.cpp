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

int n;
int a[MAXN2];
int dp[12][12][12][12][12][12];

int get(int p0,int p1, int p2, int p3, int p4, int p5) {
	int res = 0;
	for(int n0 = p0 ;n0 > 0; n0 -= (n0 & -n0)) {
		for(int n1 = p1; n1 > 0; n1 -= (n1 & -n1)) {
			for(int n2 = p2; n2 > 0; n2 -= (n2 & -n2)) {
				for(int n3 = p3;n3 > 0; n3 -= (n3 & -n3)) {
					for(int n4 = p4 ;n4 > 0; n4 -= (n4 & -n4)) {
						for(int n5 = p5 ;n5 > 0; n5 -= (n5 & -n5)) {
							res += dp[n0][n1][n2][n3][n4][n5];
/*							cerr << "get";
							db(n0);
							db(n1);
							db(n2);
							db(n3);
							db(n4);
							db(n5);
							cerr << "\n";*/
						}
					}
				}
			}
		}
	}
	
	return res;
}


void update(int p0, int p1, int p2, int p3, int p4, int p5) {
	for(int n0 = p0 ;n0 <= 10; n0 += (n0 & -n0)) {
		for(int n1 = p1 ;n1 <= 10; n1 += (n1 & -n1)) {
			for(int n2 = p2 ;n2 <= 10; n2 += (n2 & -n2)) {
				for(int n3 = p3 ;n3 <= 10; n3 += (n3 & -n3)) {
					for(int n4 = p4 ;n4 <= 10; n4 += (n4 & -n4)) {
						for(int n5 = p5 ;n5 <= 10; n5 += (n5 & -n5)) {
							dp[n0][n1][n2][n3][n4][n5]++;
/*							db(n0);
							db(n1);
							db(n2);
							db(n3);
							db(n4);
							db(n5);
							cerr << '\n';*/
						}
					}
				}
			}
		}
	}
}

signed main() {
	fast_cin();
	
	cin >> n;
	int res = 0;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		int val = a[i];
		vector<int> p;
		for(int j = 1; j <= 6; ++j) {
			p.push_back(val%10 + 1);
			val /= 10;
		}
		res += get(11 - p[0], 11 - p[1], 11 - p[2], 11 - p[3], 11 - p[4], 11 - p[5]);
		update(p[0], p[1], p[2], p[3], p[4], p[5]);
	}
	
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}