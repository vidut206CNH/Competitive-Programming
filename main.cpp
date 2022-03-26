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
int res[10];
bool ok[10][10];

string s[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		vector<string> a(6);
		for(auto &x : a) cin >> x;
		
		int idx = -1, idy = -1;
		for(int i = 0; i < 8; ++i) {
			if(s[i] == a[0]) idx = i;
			if(s[i] == a.back()) idy = i; 
		}
		
		a[idx][idy] = 1;
		a[idy][idx] = 1;
		
	}		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}