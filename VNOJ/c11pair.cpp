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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int cnt[MAXN1];
stack<int> st;

signed main() {
	fast_cin();
	
	cin >> n;
	int res = 0, extra = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		while(!st.empty() && a[st.top()] < a[i]) st.pop();
		if(!st.empty() && a[st.top()] == a[i]) {
			cnt[i] = cnt[st.top()];
			st.pop();
		}
		res += cnt[i];
		extra += cnt[i];
		if(!st.empty()) res++;
		cnt[i]++;
		st.push(i);
/*		db(res);
		cerr << "\n";*/
	}
	while(!st.empty()) st.pop();
	
	memset(cnt, 0, sizeof cnt);
	
	for(int i = n; i >= 1; --i) {
		while(!st.empty() && a[st.top()] < a[i]) st.pop();
		if(!st.empty() && a[st.top()] == a[i]) {
			cnt[i] = cnt[st.top()];
			st.pop();
		}
		res += cnt[i];
		if(!st.empty()) res++;
		cnt[i]++;
		st.push(i);
/*		db(res);
		cerr << "\n";*/
	}
	
	cout << res - extra;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}