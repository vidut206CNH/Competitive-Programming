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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int t,n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		int l,r;
		cin >> n >> l >> r;
		vector<int> left(l+1), right(r+1);
		for(int i=1;i <= l;++i) {
			cin >> left[i];
		}
		for(int i=1;i <= r;++i) {
			cin >> right[i];
		}
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());
		vector<int> d,g;
		int i=1,j=1;	
		while(i <= l || j <= r) {
			if(j > r) {
				d.push_back(left[i]);
				++i;
				continue;
			}
			if(i > l) {
				g.push_back(right[j]);
				++j;
				continue;
			}
			if(left[i] > right[j]) {
				g.push_back(right[j]);
				j++;
			}
			else if(left[i] < right[j]) {
				d.push_back(left[i]);
				i++;
			}
			else {
				i++;
				j++;
			}
		}
		if(sz(d) > sz(g)) {
			int cnt = 0;
			for(int k=0;k < sz(d)- 1;k++) {
				if(d[k] == d[k+1]) {
					cnt++;
					k++;
				}
			}
			cnt = min(cnt, (sz(d) - sz(g))/2);
			cout << sz(g) + cnt + (sz(d) - sz(g) - 2*cnt) << "\n";
		}
		else {
			
			int cnt = 0;
			for(int k=0;k < sz(g) - 1;k++) {
				if(g[k] == g[k+1]) {
					cnt++;
					k++;
				}
			}
			cnt = min(cnt,(sz(g) - sz(d))/2);
			cout << sz(d) + cnt + (sz(g) - sz(d) - 2*cnt) << "\n";
		}
		
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}