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

int st[4*MAXN1];

int n;
int a[MAXN1];


void update(int id, int l, int r, int pos, int val) {
	if(l > pos || r < pos) return;
	
	if(l == r) {
		st[id] = val;
		return;
	}
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, pos, val);
	update(id << 1|1, mid + 1, r, pos, val);
	
	st[id] = max(st[id << 1], st[id << 1|1]);
}

int get(int id, int l, int r, int u, int v) {
	if(v < l || r < u) return -1;
	
	if(u <= l && r <= v) return st[id];
	int mid = (l + r) >> 1;
	return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}

int main() {
	fast_cin();
	
	cin >> n;
	vector<pii> p;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		p.push_back({a[i], i});
	}
	
	long long res = 0;
	
	sort(p.begin(), p.end(), greater<>());
	
	memset(st, -1, sizeof st);
	int pre_val = 2e9;
	stack<pii> s;
	
	for(auto x : p) {
		int val = x.fi;
		int pos = x.se;
		
		if(val != pre_val) {
			
			while(!s.empty()) {
				int ps = s.top().fi;
				int c = s.top().se;
				
				s.pop();
				
				update(1, 1, n, ps, c);
			}
			
		} 
		
		int sum = get(1, 1, n, 1, pos - 1);
		sum = max(sum, get(1, 1, n, pos + 1, n) + 1);
		res += sum;
/*		db(res);
		cerr << "\n";*/
		s.push({pos, sum});
		pre_val = val;
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}