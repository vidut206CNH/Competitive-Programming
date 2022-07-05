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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int BLOCK_SIZE = 300;

struct qu{
	int id,l,r,k;
};

int n,q;
int a[MAXN1];
int res[MAXN1];
int BIT[MAXN1];
vector<int> values;
vector<qu> queries;
int L = 1, R = 0;


void update(int pos, int val) {
	for(;pos > 0; pos -= (pos & -pos)) BIT[pos] += val;
}

int get(int pos) {
	int ans = 0;
	for(;pos <= sz(values); pos += (pos & -pos)) ans += BIT[pos];
	return ans;
}


void add(int pos) {
	update(a[pos], +1);
	
}

void remove(int pos) {
	update(a[pos], -1);
	
}



int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		values.push_back(a[i]);
	}
	
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		int l,r,k;
		cin >> l >> r >> k;
		queries.push_back({i, l, r, k});
		values.push_back(k);
	}
	
	
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());	
	
	
	for(int i = 1; i <= n; ++i) {
		a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin() + 1;
	}
	
	for(int i = 0; i < q; ++i) {
		queries[i].k = lower_bound(values.begin(), values.end(), queries[i].k) - values.begin() + 1;
	}
	
	sort(queries.begin(), queries.end(), [&] (const qu& A, const qu& B){
		if((A.l / BLOCK_SIZE) != (B.l / BLOCK_SIZE)) {
			return ((A.l / BLOCK_SIZE) < (B.l / BLOCK_SIZE));
		}
		
		return ((A.l / BLOCK_SIZE) & 1 ? (A.r < B.r) : (A.r > B.r));
	});
	
	for(auto X : queries) {
		while(L > X.l) {
			add(--L);
		}
		
		while(R < X.r) {
			add(++R);
		}
		
		while(L < X.l) {
			remove(L++);
		}
		while(R > X.r) remove(R--);
		
		res[X.id] = get(X.k + 1);
	}
	
	for(int i = 1; i <= q; ++i) cout << res[i] << "\n";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}