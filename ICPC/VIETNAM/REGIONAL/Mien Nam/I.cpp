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

int n;
int bit[2][MAXN2];
int res[MAXN2];
pii p[MAXN2];

int get(bool type, int pos) {
	int res = 0;
	if(type == 0) for(;pos < MAXN2; pos += pos&-pos) res += bit[type][pos];
	else for(;pos > 0; pos -= pos&-pos) res += bit[type][pos];
	return res;
}

void update(bool type,int pos, int val) {
	if(type == 1) {
		for(;pos < MAXN2; pos += pos&-pos) {
			bit[type][pos] += val;
		}	
	}
	
	else {
		for(;pos > 0; pos -= pos&-pos) {
			bit[type][pos] += val;
		}
	}
}


signed main() {
	fast_cin();

	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> p[i].fi;
		p[i].se = i;
	}		
	
	sort(p + 1, p + n + 1);
	int inv = 0;
	for(int i=1;i<=n;++i) {
		int pos = p[i].se;
		res[i] = inv;
		
		inv += get(0,pos);
		update(0, pos, +1);
		
		//cout << res[i] << " "; 
	}
	//cout << "\n";
	inv = 0;
	int ans = INF;
	for(int i=n;i >= 1;--i) {
		int pos = p[i].se;
		
		res[i] += inv;
		
		inv += get(1,pos);
		update(1,pos,+1);
		ans = min(res[i], ans);
	}
	
	cout << ans;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}