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

int t;
int n,m;
int a[MAXN1];

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n >> m;
		set<int> st;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(st.empty() || a[i] < a[*st.rbegin()]) {
				st.insert(i);
			}
		}
		
		for(int i = 1; i <= m; ++i) {
			int k,d;
			cin >> k >> d;
			a[k] -= d;
			auto it = st.upper_bound(k);
			if(it != st.begin()) {
				it = prev(it);
				if(*it == k || a[*it] > a[k]) st.insert(k);
			}
			
			else st.insert(k);
			
			
			while(true) {
				auto it1 = st.upper_bound(k);
				if(it1 != st.end() && a[*it1] >= a[k]) st.erase(it1);
				else break;
			}
			
			
			cout << sz(st) << " \n"[i == m];
		}
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}