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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int BLOCK_SIZE = 505;

struct qu{
	int id, l, r;
};

int n,q;
int a[MAXN1];
int res = 0;
vector<qu> queries;
int cnt[MAXN1];
int C[MAXN1];
vector<int> values;
int answer[MAXN1];

void add(int pos) {
	
	C[cnt[a[pos]]]--;
	
	cnt[a[pos]]++;
	res = max(res, cnt[a[pos]]);
	C[cnt[a[pos]]]++;
}

void remove(int pos) {
	
	C[cnt[a[pos]]]--;
	cnt[a[pos]]--;
	
	C[cnt[a[pos]]]++;
	
	while(!C[res]) --res;
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		values.emplace_back(a[i]);
	}
	
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	
	
	for(int i = 0; i < n; ++i) {
		a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin() + 1;
	}
	
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		int l,r;
		cin >> l >> r;
		--l;
		--r;
		queries.push_back({i, l, r});
	}
	
	sort(queries.begin(), queries.end(), [&] (const qu &A, const qu & B) {
		if((A.l / BLOCK_SIZE) != (B.l / BLOCK_SIZE)) {
			return (A.l / BLOCK_SIZE) < (B.l / BLOCK_SIZE);
		}
		
		return A.r < B.r;
	});
	
	int cur_l = 0;
	int cur_r = -1;
	
	for(auto X : queries) {
		
		while(cur_l > X.l) {
			--cur_l;
			add(cur_l);
		}
		
		while(cur_r < X.r) {
			++cur_r;
			add(cur_r);
		}
		
		while(cur_l < X.l) {
			remove(cur_l);
			++cur_l;
		}
		
		while(cur_r > X.r) {
			remove(cur_r);
			--cur_r;
		}
		
		
		
		answer[X.id] = res;
		cerr << "\n";
	}
	
	for(int i = 1; i <= q; ++i) cout << answer[i] << "\n";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}