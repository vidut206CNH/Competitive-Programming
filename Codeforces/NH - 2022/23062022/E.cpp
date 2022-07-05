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
const int BLOCK_SIZE = 888;


struct qu{
	int id, l, r;
};


int n,q;
int a[MAXN1];
long long cnt[MAXN2];
long long sum[MAXN2];
long long F[MAXN2];
int L = 0, R = -1;
long long res = 0, tot = 0;
long long answer[MAXN1];
vector<qu> queries;

void add(int pos, bool type) { // 0 : left --- 1 : right
	if(!type) {
		cnt[a[pos]]++;
		sum[a[pos]] += pos;
		res += (cnt[a[pos]]*(R + 1) - sum[a[pos]]);
		tot += cnt[a[pos]];	
	}
	
	else {
		cnt[a[pos]]++;
		sum[a[pos]] += pos;
		res += (cnt[a[pos]] + tot);
		tot += cnt[a[pos]];
	}
}

void remove(int pos, bool type) {
	
	if(!type) {
		res -= (cnt[a[pos]]*(R + 1) - sum[a[pos]]);
		tot -= cnt[a[pos]];
		cnt[a[pos]]--;
		sum[a[pos]] -= pos;
	}
	
	else {
		
		res -= tot;
		tot -= cnt[a[pos]];
		
		cnt[a[pos]]--;
		sum[a[pos]] -= pos;
			
	}
	
}


int main() {
	fast_cin();
	
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	for(int i = 1; i <= q; ++i) {
		int l,r;
		cin >> l >> r;
		queries.push_back({i, l, r});
	}
	
	
	F[1] = 1;
	for(int i = 2; i < MAXN2; ++i) {
		F[i] = F[i - 1] + 1LL*(i + 1)*(i)/2;
	}
	
	sort(queries.begin(), queries.end(), [&] (const qu& A, const qu& B){
		if((A.l / BLOCK_SIZE) != (B.l / BLOCK_SIZE)) {
			return (A.l / BLOCK_SIZE) < (B.l / BLOCK_SIZE);
		}
		
		return A.r < B.r;
	});
	
	
	for(auto X : queries) {
		while(L > X.l) {
			add(--L, 0);
		}
		
		while(R < X.r) {
			add(++R, 1);
		}
		
		while(L < X.l) {
			remove(L++, 0);
		}
		
		while(R > X.r) {
			remove(R--, 1);
		}
		
		answer[X.id] = F[R - L + 1] - res;
	}
	
	for(int i = 1; i <= q; ++i) cout << answer[i] << "\n";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}