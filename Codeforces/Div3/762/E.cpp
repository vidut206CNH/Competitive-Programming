
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

int t,n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n;
		
		vector<int> cnt(n+1, 0);
		for(int i=1;i<=n;++i) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		
		sort(a+1,a+n+1);
		stack<int> extra;
		vector<int> res(n+1, -1);
		int sum = 0;
		
		for(int i=0;i<=n;++i) {
			
			if(i > 0 && cnt[i-1] == 0) {
				if(extra.empty()) {
					break;
				}
				int d = extra.top();
				extra.pop();
				sum += (i-1 - d);
			}
			res[i] = sum + cnt[i];
			
			while(i > 0 && cnt[i-1] > 1) {
				cnt[i-1]--;
				extra.push(i-1);
			}
		}
		for(auto x : res) cout << x << " ";
		cout << "\n";
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}