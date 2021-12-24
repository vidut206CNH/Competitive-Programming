/*
	Author : vidut_206_CNH
	Problem: https://oj.vnoi.info/problem/mink
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
const int MAXN1 = 17005;
const int MAXN2 = 1e6+5;

int t;
int a[MAXN1];


signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		deque<int> d;
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			while(!d.empty() && a[d.back()] >= a[i]) d.pop_back();
			d.push_back(i);
			while(i - d.front() + 1 > k) d.pop_front();
			if(i >= k) cout << a[d.front()] << " ";
		}
		cout << "\n";
	}
	
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
