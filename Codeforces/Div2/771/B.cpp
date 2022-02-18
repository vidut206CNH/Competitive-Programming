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

int t,n;
pii a[MAXN1];
int bit[MAXN1];
int sum[MAXN1];


void update(int pos,int val) {
	for(;pos <= n; pos += (pos & -pos)) {
		bit[pos]++;
		sum[pos] += val;
	}
}

bool get(int pos, int g) {
	int cnt = 0, d = 0;
	for(;pos > 0; pos -= (pos & -pos)) {
		cnt += bit[pos];
		d += sum[pos];
	}
	
	return (cnt == g*d);
}

signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		for(int i = 1; i <= n; ++i) {
			bit[i] = 0;
			sum[i] = 0;
		}
		
		for(int i = 1; i <= n;++i) {
			cin >> a[i].fi;
			a[i].se = i;
		}
		
		sort(a + 1, a + n + 1);
		bool bad = false;
		
		for(int i = n; i  >= 1; --i) {
			int d = (a[i].fi%2 == 0 ? -1 : 1);
			int pos = a[i].se;
			
			if(get(pos, -d)) {
				update(pos, d);
			}
			else {
				bad = true;
				break;
			}
		}
		
		cout << (bad ?  "No\n" : "Yes\n");
	}
		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}