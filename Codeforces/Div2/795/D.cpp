/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
#define int long long
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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int t,n;
long long a[MAXN1];
long long f[MAXN1];
long long rmq[2][MAXN1][30];
int L[MAXN1], R[MAXN1];


int get_MAX(int l, int r) {
	int k = log2(r - l + 1);
	
	return max(rmq[0][l][k], rmq[0][r - (1 << k) + 1][k]);
}

int get_MIN(int l ,int r) {
	int k = log2(r - l + 1);
	return min(rmq[1][l][k], rmq[1][r - (1 << k) + 1][k]);
} 


signed main() {
	fast_cin();
	
	cin >> t;
	
	
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) {
			f[i] = f[i - 1] + a[i];
		}
		
		for(int i = 0; i <= n; ++i) {
			rmq[0][i][0] = f[i];
			rmq[1][i][0] = f[i];
		}
		
		for(int j = 1; j < 30; ++j) {
			for(int i = 0; i <= n; ++i) {
				if(i + (1 << j) - 1 > n) break;
				rmq[0][i][j] = max(rmq[0][i][j - 1], rmq[0][i + (1 << (j - 1))][j - 1]);
				rmq[1][i][j] = min(rmq[1][i][j - 1], rmq[1][i + (1 << (j - 1))][j - 1]);
				
			}
		}
		
		deque<int> d;
		for(int i = 1; i <= n; ++i) {
			while(!d.empty() && a[d.back()] <= a[i]) d.pop_back();
			
			if(d.empty()) {
				L[i] = 1;
			}
			
			else {
				L[i] = d.back() + 1;
			}
			
			d.push_back(i);
		}
		
		d.clear();
		
		for(int i = n; i >= 1; --i) {
			
			while(!d.empty() && a[d.back()] <= a[i]) d.pop_back();
			if(d.empty()) {
				R[i] = n;
			}
			
			else {
				R[i] = d.back() - 1;
			}
			d.push_back(i);
			
		} 
		
		
		bool bad = false;
		
		for(int i = 1; i <= n; ++i) {
			long long sum = f[i - 1] - get_MIN(L[i] - 1, i - 1);
			sum += (get_MAX(i, R[i]) - f[i]);
			bad |= (sum > 0);
		}
		cout << (bad ? "NO\n" : "YES\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}