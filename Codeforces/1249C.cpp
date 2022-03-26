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
const int inf = 3e18 + 7;

int t;

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res = res*a;
		a = a*a;
		b /= 2;
	}
	return res;
}

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> bits;
		int d = n;
		while(d) {
			bits.push_back(d%3);
			d /= 3;
		}
		
		reverse(bits.begin(), bits.end());
		//int res = inf;
		vector<int> sum(sz(bits));
		int res = -1;
		for(int i = 0; i < sz(bits); ++i) {
			
			if(bits[i] == 2) {
				int id = i - 1;
				while(id >= 0 && bits[id] == 1) {
					--id;
				}
				//db(id);
				res = power(3, sz(bits) - id - 1);
				if(id >= 0) res += sum[id];
				break;
			}
			
			sum[i] = bits[i]*(power(3, sz(bits) - i - 1));
			if(i > 0) sum[i] += sum[i - 1];
		}	
		
		cout << (res == -1 ? n : res) << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}