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
const int MAXN1 = 3e4+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

struct data{
	int l;
	int r;
	int val;
	bool operator() (const data& A, const data& B) {
		return A.r < B.r;
	}
};

int n,q;
int bit[MAXN1];
int last[MAXN2];
data a[MAXN1];
data p[200005];


int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= pos&-pos) res += bit[pos];
	return res;
}

void update(int pos, int val) {
	for(;pos <= n;pos += pos&-pos) bit[pos] += val;
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		a[i].l = i;
		a[i].r = i;
		a[i].val = x;
	}
	
	cin >> q;
	for(int i=1;i<=q;++i) {
		cin >> p[i].l >> p[i].r;
		p[i].val = i;
	}
	sort(p+1,p+q+1, data());
	
	int pos = 1;
	vector<int> res(q + 1);
	
	for(int i=1;i<=q;++i) {
		while(pos <= n && a[pos].r <= p[i].r) {
			int val = a[pos].val;
			update(a[pos].r, +1);
			if(last[val] > 0) update(last[val], -1);
			last[val] = a[pos].r;



			pos++;
		}
		//db(p[i].r);
			
		res[p[i].val] = get(p[i].r) - get(p[i].l - 1);
	}
	
	for(int i=1;i<=q;++i) cout << res[i] << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}