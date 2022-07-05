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
const int BLOCK_SIZE = 707;

struct qu{
	int id,l,r;
};

int n,q;
int a[MAXN1];
int cnt[MAXN2];
long long answer[MAXN1];
long long res = 0;
vector<qu> queries;

int L = 0, R = -1;


void add(int pos) {
	res += a[pos]*(2*cnt[a[pos]] + 1);
	cnt[a[pos]]++;
}

void remove(int pos) {
	--cnt[a[pos]];
	res -= a[pos]*(2*cnt[a[pos]] + 1);
}

int main() {
	fast_cin();
	
	
	cin >> n >> q;
	for(int i  = 1; i <= n; ++i) cin >> a[i];
	
	
	for(int i = 1; i <= q; ++i) {
		int l,r;
		cin >> l >> r;
		queries.push_back({i, l, r});
	}
	
	sort(queries.begin(), queries.end(), [&] (const qu &A, const qu &B) {
		if((A.l / BLOCK_SIZE) != (B.l / BLOCK_SIZE)) {
			return (A.l / BLOCK_SIZE) < (B.l / BLOCK_SIZE);
		}
		
		return ((A.l / BLOCK_SIZE) & 1 ? (A. r < B.r) : (A.r > B.r));
	});

	for(auto X : queries) {
		while(L > X.l) {
			add(--L);
		}
		
		while(R < X.r) {
			add(++R);
		}
		
		while(L < X.l) remove(L++);
		while(R > X.r) remove(R--);
		
		answer[X.id] = res;
	}	
	
	for(int i = 1; i <= q; ++i) cout << answer[i] << "\n";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}