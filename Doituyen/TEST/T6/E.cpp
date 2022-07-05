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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;


struct book{
	int id, mask, cost;
};


int m,n;
int a[MAXN2];
book b[MAXN2];
int v[MAXN1];
pii C[2][(1 << 10) + 5];
long long dp[(1 << 10) + 5][12];
long long F[(1 << 10) + 5];


long long calc(int mask, int bit) {
	if(bit < 0) return v[mask];
	return dp[mask][bit];
}

void solve() {
	for(int i = 1; i <= n; ++i) {
		v[a[i]]++;
	}
	
	for(int mask = 0; mask < (1 << 9); ++mask) {
		
		for(int i = 0; i < 9; ++i) {
			if(mask >> i & 1) {
				dp[mask][i] = calc(mask, i - 1) + calc(mask ^ (1 << i), i - 1);
			}
			
			else dp[mask][i] = calc(mask, i - 1);
		}
		
		F[mask] = dp[mask][8];
	}
	
	long long best = 0, sum = 1e18;
	pii res;
	
	for(int mask1 = 0; mask1 < (1 << 9); ++mask1) {
		for(int mask2 = 0;mask2 < (1 << 9); ++mask2) {
			if(mask1 == mask2 && C[1][mask1].fi == 0) continue;
			if(C[0][mask1].fi == 0 || C[0][mask2].fi == 0) continue;
			
			long long tmp = C[0][mask1].fi + (mask1 == mask2 ? C[1][mask1].fi : C[0][mask2].fi);
			
			if(F[mask1|mask2] > best) {
				best = F[mask1|mask2];
				sum = tmp;
				res.fi = C[0][mask1].se;
				res.se = (mask1 == mask2 ? C[1][mask2].se : C[0][mask2].se);
			}
			if((F[mask1|mask2] == best) && sum > tmp) {
				sum = tmp;
				res.fi = C[0][mask1].se;
				res.se = (mask1 == mask2 ? C[1][mask2].se : C[0][mask2].se);	
			}
		}
	}
	
	cout << res.fi << " " << res.se << "\n";
}

int main() {

	
	fast_cin();
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		while(t--) {
			int x;
			cin >> x;
			a[i] |= (1 << (x - 1));
		}
	}
	
	for(int i = 1; i <= m; ++i) {
		int t;
		cin >> b[i].cost >> t;
		
		while(t--) {
			int x;
			cin >> x;
			b[i].mask |= (1 << (x - 1));
		}
		
		b[i].id = i;		
		int maskk = b[i].mask;
		
		if(C[0][maskk].fi == 0) {
			C[0][maskk].fi = b[i].cost;
			C[0][maskk].se = b[i].id;
		}
		
		else if(C[1][maskk].fi == 0) {
			C[1][maskk].fi = b[i].cost;
			C[1][maskk].se = b[i].id;
		}
		
		else if(b[i].cost < C[1][maskk].fi) {
			C[1][maskk].fi = b[i].cost;
			C[1][maskk].se = b[i].id;
		}
		
		if(C[0][maskk].fi > C[1][maskk].fi && C[1][maskk].fi != 0) swap(C[0][maskk], C[1][maskk]);
	}
	
	
	solve();
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}