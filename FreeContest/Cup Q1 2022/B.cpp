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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int st[4*MAXN1];
int a[MAXN1];

void build(int id, int l, int r) {
	if(l == r) {
		st[id] = a[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1|1, mid + 1, r);
	
	st[id] = max(st[id << 1], st[id << 1|1]);
}

int findleft(int val) {
	int id = 1;
	int l = 1, r = n;
	while(l < r) {
		int d = st[id << 1];
		int mid = (l + r) >> 1;
		if(d >= val) {
			id = id << 1;
			r = mid;
		}
		else {
			id = id << 1|1;
			l = mid + 1;
		}
	}
	
	return l;
}

int findright(int val) {
	int id = 1;
	int l = 1, r = n;
	while(l < r) {
		int d = st[id << 1|1];
		
		int mid = (l + r) >> 1;
		if(d >= val) {
			id = id << 1|1;
			l = mid + 1;
		}
		else {
			id = id << 1;
			r = mid;
		}
	}
	
	return l;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	build(1, 1, n);
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		int pos1 = findleft(a[i]);
		int pos2 = findright(a[i]);
/*		db(pos1);
		db(pos2);*/
		//cerr << "\n";
		
		res = max(res, a[i]*(max(abs(pos1 - i), abs(pos2 - i)) - 1));
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}