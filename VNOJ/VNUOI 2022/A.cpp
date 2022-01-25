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

int n;
pii a[MAXN1];
int bit[MAXN1];
int p[MAXN1];

int get(bool d, int pos) {
	int res = 0;
	if(d) for(;pos <= n;pos += pos & (-pos)) res += bit[pos];
	else for(;pos > 0; pos -= pos & (-pos)) res += bit[pos];
	return res;
}


void update(bool d, int pos) {
	if(d) for(;pos > 0; pos -= pos&(-pos)) bit[pos]++;
	else for(;pos <= n; pos += pos&(-pos)) bit[pos]++;
}

signed main() {
	//fast_cin();
	
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	
	sort(a+1,a+n+1);
	
	int sum = 0;
	
	for(int i=1;i<=n;++i) {
		int val = a[i].fi;
		int pos = a[i].se;
		p[val] = sum;
		sum += get(1, pos);
		update(1, pos);
	}
	
	int g = sum,res, best = inf;
	sum = 0;
	memset(bit, 0, sizeof bit);
	
	for(int i=n;i>= 1; --i) {
		int val = a[i].fi;
		int pos = a[i].se;
		
		p[val] += sum;
		
		if(best >= p[val]) {
			best = p[val];
			res = val;
		}
		sum += get(0, pos);
		update(0, pos);
	}
	
	cout << res << " " << g - best;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}