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

vector<int> a;
int f[13];
bool ok[13];
bool bad[13];

int main() {
	fast_cin();
	
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i <= 12; ++i) f[i] = f[i - 1]*i;
	
	int x;
	while(cin >> x) {
		a.push_back(x);
	}
	
	int res = 0;
	for(int i = 0; i < sz(a) - 1; ++i) {
		for(int val = 1; val < a[i]; ++val) {
			if(bad[val]) continue;
			res += f[sz(a) - 2 - i]; 
		}
		
		bad[a[i]] = true;
	}
	
	int X = a.back();
	vector<int> ans;
	
	for(int i = 0; i < sz(a) - 1; ++i) {
		for(int val = 1; val <= sz(a) - 1; ++val) {
			if(ok[val]) continue;
			
			if(X <= f[(sz(a) - 2 - i)]) {
				ans.push_back(val);
				ok[val] = true;
				break;
			}
			
			X -= f[sz(a) - 2 - i];
		}
	}
	
	
	
	cout << res + 1 << "\n";
	for(auto val : ans) cout << val << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}