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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,p;
int a[MAXN1];
deque<int> pmin,pmax;




signed main() {
	fast_cin();
	
	cin >> n >> p;
	for(int i=1;i<=n;++i) cin >> a[i];
	
	
	int ans = 0;
	int pos = 0;
	
	for(int i=1;i<=n;++i) {
		while(!pmin.empty() && a[pmin.back()] > a[i]) pmin.pop_back();
		while(!pmax.empty() && a[pmax.back()] < a[i]) pmax.pop_back();
		
		pmin.push_back(i);
		pmax.push_back(i);
		
		
		while(!pmin.empty() && !pmax.empty() && a[pmax.front()] - a[pmin.front()] >  p) {
			if(pmin.front() < pmax.front()) {
				pos = pmin.front();
				pmin.pop_front();
			} else {
				pos = pmax.front();
				pmax.pop_front();
			}
		}
		// db(pmin.front());
		// db(pmax.front());
		// cerr << "\n";
		ans = max(ans, i - pos);
		
	}	
	
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}