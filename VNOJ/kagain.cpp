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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 3e4+5;
const int MAXN2 = 1e6+5;

int n;
int a[MAXN1];
int g[MAXN1];
int L[MAXN1];
int R[MAXN1];


signed main() {
	fast_cin();
	int t;
	cin >> t;
	while(t--) {
		deque<int> dl,dr;
		cin >> n;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
		}	
		
		int res = 0,id = 0;
		
		
		for(int i=1;i<=n;++i) {
			while(!dl.empty() && a[dl.back()] >= a[i]) dl.pop_back();
			int m = i;
			L[i] = 1;
			if(!dl.empty()) {
				m = i - dl.back();
				L[i] = dl.back() + 1;
			}
			dl.push_back(i);
			g[i] = a[i]*m;
		}
		
		for(int i=n;i>0;--i) {
			while(!dr.empty() && a[dr.back()] >= a[i]) dr.pop_back();
			int m = n + 1 - i;
			R[i] = n;
			if(!dr.empty()) {
				m = dr.back() - i;
				R[i] = dr.back() - 1;
			}
			dr.push_back(i);
			g[i] = g[i] + a[i]*m - a[i];
			//cout << g[i] << "  ";
			if(g[i] == res) {
				id = (L[id] < L[i]) ? id : i;
			}
			if(g[i] > res) {
				id = i;
				res = g[i];
			}
		}
		
		cout << g[id] << " " << L[id] << " " << R[id] << "\n";
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}