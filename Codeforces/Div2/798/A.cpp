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

int t;
string a,b;

int main() {
	fast_cin();
	
	
	cin >> t;
	while(t--) {
		int n,m, k;
		cin >> n >> m >> k >> a >> b;
		string res = "";
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ida = 0,idb = 0, cnta = 0, cntb = 0;
		while(ida < n && idb < m) {
			if(idb == m) {
				res += a[ida++];
				cnta++;
				continue;
			}
			
			if(ida == n) {
				res += b[idb++];
				cntb++;
				continue;
			}
			
			if(a[ida] < b[idb]) {
				if(cnta < k) {
					res += a[ida++];
					cntb = 0;
					cnta++;
				}
				else {
					res += b[idb++];
					cnta = 0;
					cntb++;
				}
			}
			
			else {
				if(cntb < k) {
					cntb++;
					cnta = 0;
					res += b[idb++];
				}
				else {
					cnta++;
					cntb = 0;
					res += a[ida++];
				}
			}
		}
		
		cout << res << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}