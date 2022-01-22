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
const int MAXN1 = 1e8+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,q;
int a[MAXN2];
int s[MAXN2];
bool possible[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	possible[0] = true;
	for(int i=n;i>=1;--i) {
		s[i] = s[i+1] + a[i];
		possible[s[i]] = true;
	}
	
	for(int i=1;i<=q;++i) {
		int val;
		cin >> val;
		if(val > s[1]) {
			cout << "No\n";
			continue;
		}
		int sum = 0;
		bool found = 0;
		for(int pos=0;pos<n;++pos) {
			sum += a[pos];
			if(sum > val) break;
			if(possible[val - sum]) {
				found = true;
				break;
			}
		}
		
		cout << (found ? "Yes\n" : "No\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}