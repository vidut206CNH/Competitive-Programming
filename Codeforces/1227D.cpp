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


struct data{
	int num;
	int pos;
	int id;
	bool operator() (const data& A, const data& B) {
		return A.num < B.num;
	}
};

int n,q;
pii a[MAXN1];
int v[MAXN1];
data query[MAXN1];
int bit[MAXN1];


int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos&-pos)) res += bit[pos];
	return res;
}

void update(int pos) {
	for(;pos <= n; pos += (pos&-pos)) bit[pos]++;
}


signed main() {
	fast_cin();
	
	
	cin >> n;
	
	for(int i=1;i<=n;++i) {
		cin >> a[i].fi;
		v[i] = a[i].fi;
		a[i].se = i;
	}
	
	sort(a+1,a+n+1, [&] (const pii& A, const pii& B) {
		if(A.fi == B.fi) return A.se < B.se;
		return A.fi > B.fi;
	});
	
	cin >> q;
	vector<int> res(q+1);
	
	for(int i=1;i<=q;++i) {
		cin >> query[i].num >> query[i].pos;
		query[i].id = i;		
	}
	
	sort(query + 1, query + q + 1, data());
	
	int id = 0;
	
	for(int i=1;i<=q;++i) {
		while(query[i].num > id) {
			++id;
			int pos = a[id].se;
			update(pos);
		}
		
		int k = query[i].pos;
		int d = query[i].id;
		
		int l = 1, r = n;
		while(l <= r) {
			int mid = (l+r) >> 1;
			int cnt = get(mid);
			
			if(cnt >= k) {
				res[d] = v[mid];
				r = mid - 1;
			} else l = mid + 1;
		}
	}
	
	for(int i=1;i<=q;++i) cout << res[i] << "\n";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}