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

int n,k;
int a[MAXN1];
vector<int> p[2];

int main() {
	fast_cin();
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = (a[i] < 20 ? 1 : 0);
		k -= a[i];
	}
	
	int cnt = -1;
	for(int L = 1; L <= n; ) {
		cnt++;
		int R = L;
		while(R <= n && a[R + 1] == a[R]) {
			++R;
		}
		
		if(a[L] == 0) {
			p[R == n].push_back(R - L + 1);
		}
		
		L = R + 1;
	}
	
	sort(p[0].begin(), p[0].end());
	
	int best = (a[1] == 1 && sz(p[0]) == 0 ? 1 : 0);
	for(int mask = 0; mask < (1 << sz(p[1])); ++mask) {
		int sum = 0;
		int tmp = 0;
		for(int i = 0; i < sz(p[1]); ++i) {
			if(mask >> i & 1) {
				sum += p[1][i];
				tmp++;
			}
		}
		
		for(int i = 0; i < sz(p[0]); ++i) {
			if(sum + p[0][i] > k) break;
			tmp += 2;
			sum += p[0][i];
		}
		
		if(sum <= k) best = max(best, tmp);
	}
	if(k < 0) cout << -1;
	else cout << cnt - best;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}