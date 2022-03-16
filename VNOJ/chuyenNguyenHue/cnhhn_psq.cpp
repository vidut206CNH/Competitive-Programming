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

bool isprime[MAXN2];
int L[MAXN1];
int R[MAXN1];

signed main() {
	fast_cin();
	memset(isprime, true, sizeof isprime);
	isprime[0] = isprime[1] = false;
	for(int i = 2;i*i < MAXN2; ++i) {
		if(isprime[i]) {
			for(int j = i*i; j < MAXN2; j += i) isprime[j] = false;
		}
	}
	
	
	int m,n;
	cin >> m >> n;
	
	vector< vector<int> > a(m + 5, vector<int>(n + 5));
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			a[i][j] = (isprime[a[i][j]]);
		}
	}
	
	vector<int> b(n + 5);
	stack<int> st;
	int res = 0;
	
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			
			if(a[i][j]) b[j]++;
			else b[j] = 0;
/*			db(b[j]);
			cerr << " ";*/
		}
		//cerr << "\n";
		
		while(!st.empty()) st.pop();
		
		for(int id = 1; id <= n; ++id) {
			while(!st.empty() && b[st.top()] >= b[id]) st.pop();
			if(st.empty()) {
				L[id] = id;
			}
			else L[id] = id - st.top();
			st.push(id);
		}
		
		while(!st.empty()) st.pop();
		
		for(int id = n; id >= 1; --id) {
			while(!st.empty() && b[st.top()] >= b[id]) st.pop();
			if(st.empty()) {
				R[id] = n - id + 1;
			}
			else R[id] = st.top() - id;
			st.push(id);
		}
		
		for(int id = 1; id <= n; ++id) {
			int d = L[id] + R[id] - 1;
/*			db(b[id]);
			db(L[id]);
			db(R[id]);
			cerr << "\n";*/
			res = max(res, min(d*d, b[id]*b[id]));
		}
		
		cerr << "\n";
			
	}
	
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}