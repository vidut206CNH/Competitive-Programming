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

int n,a,b;

signed main() {
	fast_cin();
	
	cin >> n >> a >> b;
	cin.ignore();
	vector<char> p(n);
	for(int i=0;i<n;++i) cin >> p[i];
	vector<int> d;
	for(int i=0;i<n;) {
		if(p[i] == '*') {
			++i;
			continue;
		}
		int j = i+1;
		while(j < n && p[j] == p[i]) ++j;
		d.push_back(j - i);
		i = j;
	}
	sort(d.begin(), d.end(), greater<int>());
	int sum = a + b,id = 0;
	
	while((a > 0 || b > 0) && id < sz(d)) {
		if(a < b) swap(a,b);
				
		int g = d[id]/2;
		int diff = min(a, b);
		
		if(diff < g) {
			b -= diff;
			a -= min(a, diff + 1);
		} else {
			if(d[id]%2) {
				b -= g;
				a -= min(a, d[id] - g);
			} else {
				b -= (g - 1);
				a -= (g);
			}
		}
		++id;
	}
	
	cout << sum - (a + b);
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}