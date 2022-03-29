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
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n;
char a[MAXN1][MAXN1];
int f[MAXN1];
int L[MAXN1], R[MAXN1];
int cnt[MAXN1];

int func(int g) {
	return g*(g - 1)/2;
}

stack<int> st;

signed main() {
	fast_cin();
	
	cin >> m >> n;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	int res = 0;
	
	for(int r = 1; r <= m; ++r) {
		
		for(int c = 1; c <= n; ++c) {
			if(a[r][c] == '1') f[c]++;
			else f[c] = 0;
		}
		
		while(!st.empty()) st.pop();
		
		for(int c = 1; c <= n; ++c) {
			while(!st.empty() && f[st.top()] >= f[c]) st.pop();		
			
			if(st.empty()) {
				L[c] = c;
			}
			else L[c] = (c - st.top());
			st.push(c);
			
		}
		
		while(!st.empty()) st.pop();
		
		for(int c = n; c >= 0; --c) {
			while(!st.empty() && f[st.top()] > f[c]) st.pop();
			
			if(st.empty()) {
				R[c] = (n + 1 - c);
			}
			else R[c] = (st.top() - c);
			st.push(c);
		}
		
		while(!st.empty()) st.pop();
		
		for(int c = 1; c <= n; ++c) {
/*			db(L[c]);
			db(R[c]);
			db(f[c]);
			cerr << "\n";*/
			res += L[c]*R[c]*f[c];
		}
/*		
		db(res);
		for(int c = 1; c <= n; ++c) {
			while(!st.empty() && f[st.top()] > f[c]) {
			 	res -= cnt[f[st.top()]];
				cnt[f[st.top()]] = 0;
				st.pop();
			}
			
			if(!st.empty() && f[st.top()] == f[c]) {
				st.pop();
			}
			
			cnt[f[c]]++;
			
			st.push(c);
		}
		
		while(!st.empty()) {
			res -= (cnt[f[st.top()]] - 1);
			cnt[f[st.top()]] = 0;
			st.pop();
		}*/
		
/*		db(res);
		cerr << "\n";*/
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}