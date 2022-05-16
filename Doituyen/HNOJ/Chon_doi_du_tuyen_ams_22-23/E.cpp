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

struct point1{
	int id, x, y, val;
};

struct point2{
	int id, x, y, u, v;
};


int m,n,q;
int id1 = 0, id2 = 0;
point1 query1[MAXN1];
point2 query2[MAXN1];
int bit[MAXN1];
int lim = 0;
map<int,int> mp;

void update(int pos, int val) {
	for(;pos <= lim;pos += (pos & -pos)) {
		bit[pos] += val;
	}
}

int get(int pos) {
	int res = 0;
	for(;pos > 0; pos -= (pos & -pos)) {
		res += bit[pos];
	}
	
	return res;
}

void sub1() {
	
	for(int i = 1; i <= q; ++i) {
		int type;
		cin >> type;
		if(type == 1) {
			int x,y,val;
			cin >> x >> y >> val;
			query1[id1++] = {i, x, y, val};
		}
		
		else {
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			query2[id2++] = {i, x, y, u, v};
			int res = 0;
			for(int j = 0; j < id1; ++j) {
				point1 data = query1[j];
				
				int s = data.x;
				int t = data.y;
				int val = data.val;
				if(x <= s && s <= u && y <= t && t <= v) res += val;
			}
			
			
			cout << res << "\n";
		}
	}
	
}


void sub23() {
	set<int> st;
	st.insert(lim);
	
	int d = 0;
	for(int i = 0; i < id1; ++i) {
		st.insert(query1[i].y);
	}
	
	for(int i = 0; i < id2; ++i) {
		st.insert(query2[i].y);
		st.insert(query2[i].v);
	}
	
	for(auto x : st) {
		mp[x] = ++d;
	}
	
	for(int i = 0; i < id1; ++i) {
		query1[i].y = mp[query1[i].y];
	}
	
	for(int i = 0; i < id2; ++i) {
		query2[i].y = mp[query2[i].y];
		query2[i].v = mp[query2[i].v];
	}
	
	lim = mp[lim];
	
	int p1 = 0, p2 = 0;
	while(p1 < id1 || p2 < id2) {
		
		while(p1 < id1 && query1[p1].id < query2[p2].id) {
			update(query1[p1].y, query1[p1].val);
			++p1;
		}
		
		cerr << "\n";
		
		if(p2 < id2) {
			int x = query2[p2].x;
			int u = query2[p2].u;
			
			if(query1[0].x < x || query1[0].x > u) {
				cout << 0 << "\n";
				++p2;
				continue;
			}
			
			int y = query2[p2].y;
			int v = query2[p2].v;
			cout << get(v) - get(y - 1) << "\n";
			++p2;
		}
		
	}
}


void sub4() {
	
}

signed main() {
	fast_cin();
	
	
	cin >> m >> n >> q;
	
	if(q <= 5000) {
		sub1();
		return 0;
	}
	
	
	for(int i = 1; i <= q; ++i) {
		int type;
		cin >> type;
		if(type == 1) {
			int x, y, val;
			cin >> x >> y >> val;
			query1[id1++] = {i, x, y, val};
		}
		
		else {
			int x,y,u,v;
			cin >> x >> y >> u >> v;
			query2[id2++] = {i, x, y, u, v};
		}
	}
	
	bool rowa = true, cola = true;
	
	for(int i = 0; i < id1; ++i) {
		rowa &= (query1[i].x == query1[1].x);
		cola &= (query1[i].y == query1[1].y);
	}
	
	if(cola || rowa) {
		lim = n;
		
		if(cola) {
			lim = m;
			for(int i = 0; i < id1; ++i) {
				swap(query1[i].x, query1[i].y);
			}
			
			for(int i = 0; i < id2; ++i) {
				swap(query2[i].x, query2[i].y);
				swap(query2[i].u, query2[i].v);
			}
		}
		
		sub23();
		return 0;
	}
	
	else {
		sub4();
	}
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
