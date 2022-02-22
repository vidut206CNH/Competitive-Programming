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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int cnt[MAXN1];

signed main() {
	fast_cin();
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	stack<int> st;
	for(int i = 1; i <= n; ++i) {
		int cur = a[i];
		if(!st.empty() && cur == a[st.top()]) {
			
			cnt[i] = cnt[st.top()] + 1;
			st.push(i);
			if(cnt[i] == cur) {
				for(int t = 1; t <= cur; ++t) {
					st.pop();
				}
				cnt[i] = 0;
			}
		} else {
			cnt[i] = 1;
			st.push(i);
		}
/*		db(cnt[i]);
		cerr << "\n";*/
		
		cout << sz(st) << "\n";
	}
	

	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}