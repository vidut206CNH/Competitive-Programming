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
 
long long n,k, res = 1;
 
int main() {
	fast_cin();
	
	cin >> n >> k;
	set<long long> st;
	if(k <= n) st.insert(k);
	
	if(k < 10) {
		while(k <= n) {
			st.insert(k);
			k *= 10;
		}
		cout << sz(st) << "\n";
		return 0;
	}
	
	if(k%10) {
		
		long long K = k, tmp = k;
	
		
		vector<int> x;
		
		while(k) {
			x.push_back(k%10);
			k /= 10;
		}
		
		long long d = 0;
		
		for(auto val : x) {
			d = d*10 + val;
		}
		
		
		long long D = d*10;
			
		while(D <= n) {
			if(K < D) st.insert(D);
			D *= 10;
		}
		
		if(K < d) {
			while(K <= n) {
				st.insert(K);
				K *= 10LL;
			}
		}
		
	}
	
	
	cout << sz(st);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}