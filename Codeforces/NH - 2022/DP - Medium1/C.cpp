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
vector<int> d[MAXN1];
pii a[MAXN1];
int bit[MAXN1];


void update(int pos, int val) {
	for(;pos > 0; pos -= (pos & -pos)) bit[pos] += val;
}

int get(int pos) {
	int res = 0;
	for(;pos <= n; pos += (pos & -pos)) res += bit[pos];
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n;
	priority_queue<int> pq;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		d[x].push_back(i);
	}
	bool bad = false;
	
	for(int i = n; i >= 1; --i) {
		for(auto x : d[i]) {
			pq.push(x);
		}
		
		if(pq.empty()) {
			bad = true;
			break;
		}
		
		a[i] = {pq.top(), i};
		pq.pop();
	}
	
	if(bad) {
		cout << -1;
		exit(0);
	}
	
	sort(a + 1, a + n + 1);
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		int val = a[i].fi;
		int pos = a[i].se;
		res += get(pos);
		update(pos, +1);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}