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


struct points {
	int type, id, val;
};

int n;
pii a[MAXN1];
vector<points> p;
int bit[2*MAXN1];


void update(int pos, int val) {
	for(;pos <= 2*n; pos += (pos & -pos)) bit[pos] += val;
}

int get(int pos) {
	int res  = 0;
	for(;pos > 0; pos -= (pos & -pos)) res += bit[pos];
	return res;
}


int main() {
	fast_cin();
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
		if(a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
		
		p.push_back({0, i, a[i].fi});
		p.push_back({1, i, a[i].se});		
	}
	
	sort(p.begin(), p.end(), [&] (const points &A, const points &B) {
		return (A.val < B.val);
	});
	
	long long res = 0;
	for(auto e : p) {
		int type = e.type;
		int id = e.id;
		int val = e.val;
		
		if(type == 0) {
			update(val, +1);
		}
		
		else {
			update(a[id].fi, -1);
			res += (get(val) - get(a[id].fi - 1));
		}
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}