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


int M[MAXN1][20];
int f[MAXN1];
vector<int> pos[2*MAXN1];
string s;


int main() {
	fast_cin();
	
	cin >> s;
	s = '0' + s;
	int n  = sz(s) - 1;
	
	for(int i = 1; i <= n; ++i) {
		f[i] = f[i - 1] + (s[i] == '(' ? +1 : -1);
		pos[f[i] + MAXN1].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i) M[i][0] = f[i];
	
	
	for(int j = 1; (1 << j) < MAXN1; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(i + (1 << j) - 1 > n) break;
			M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	int best = 0, res = 1;
	
	for(int i = 1; i <= n; ++i) {
		int low = i, high = n, p = 0;
		
		while(low <= high) {
			int mid = (low + high) >> 1;
			int k = log2(mid - i + 1);
			int val = min(M[i][k], M[mid - (1 << k) + 1][k]);
			if(val - f[i - 1] < 0) {
				high = mid - 1;
			}
			
			else {
				p = mid;
				low = mid + 1;
			}
		}
		
		
		int t = upper_bound(pos[f[i - 1] + MAXN1].begin(), pos[f[i - 1] + MAXN1].end(), p) - pos[f[i - 1] + MAXN1].begin() - 1;
		if(t != -1) {
/*			db(i);
			db(pos[f[i - 1] + MAXN1][t]);
			cerr << "\n";*/
			int len = pos[f[i - 1] + MAXN1][t] - i + 1;
			if(len > best) {
				best = len;
				res = 0;
/*				db(i);
				db(best);
				db(p);
				cerr << "\n";*/
			}
			if(len == best) res++;
		}
	}
	
	cout << best << " " << res;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}