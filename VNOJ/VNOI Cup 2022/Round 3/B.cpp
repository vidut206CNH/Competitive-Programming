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

struct node{
	pii close;
	pii open;
};

int n,q;
char a[MAXN1];
node st[MAXN1*4];
int res[MAXN1*4];

int comb(node & res, const node& A, const node &B) {
	int g = min(A.open.se, B.close.fi);
	res.close.fi = A.close.fi;
	res.close.se = B.close.se;
	res.open.fi = A.open.fi;
	
	
	
	return g;
}

void build(int id, int l, int r) {
	if(l == r) {
		if(a[l] == ')') {
			st[id].close.fi++;
			st[id].close.se++;
		}
		
		if(a[l] == '(') {
			st[id].open.fi++;
			st[id].open.se++;
		}
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	
	st[id] = comb(st[id << 1], st[id << 1|1]);
}

int main() {
	fast_cin();
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for(int i = 1; i <= q; ++i) {
		int l,r;
		cout << get(1,1,n,l,r) << "\n";
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}