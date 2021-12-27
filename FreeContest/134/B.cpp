/*
	Author : vidut_206_CNH
	Link problem: 
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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "


typedef pair<int,int> pii;


const int MOD = 1e9 + 7;
const int MAXN1 = 2e4+5;
const int MAXN2 = 1e6+5;


int n;
vector< vector<bool> > st(4*MAXN1, vector<bool>(105)), a(MAXN1, vector<bool>(105));
int p[MAXN2];



void factor(vector<bool>& A, int val) {
	if(val==1) return;
	A[p[val]] = (A[p[val]]^1);
	factor(A, val/p[val]);
}

void comb(vector<bool>& des, const vector<bool>& A, const vector<bool>& B) {
	for(int i=2;i<=100;++i) {
		des[i] = A[i]^B[i];
	}
}



void build(int node, int l, int r) {
	if(l == r) {
		st[node] = a[l];
		return;
	}
	
	int mid = (l+r) >> 1;
	build(node << 1, l, mid);
	build(node << 1|1, mid + 1, r);
	
	comb(st[node], st[node << 1], st[node << 1|1]);
}


void update(int node,int l,int r,int &pos,int& val) {
	if(l==r) {
		vector<bool> tmp(105);
		factor(tmp, val);
		comb(st[node], tmp, st[node]);
		return;
	}
	
	int mid = (l+r) >> 1;
	if(pos <= mid) update(node << 1, l, mid, pos, val);
	else update(node << 1|1, mid + 1, r, pos, val);
	
	comb(st[node], st[node << 1], st[node << 1|1]);
}


void get(int node,int l,int r,int& u, int &v, vector<bool>& res) {
	if(u <= l && r <= v) {
		comb(res, res, st[node]);
		/*
		cout << l << " " << r << "\n";
		for(int i=2;i<=100;++i) cout << st[node][i];
		cout << "\n";
		for(int i=2;i<=100;++i) cout << res[i];
		cout << "\n\n";
		*/
		return;
	}
	int mid = (l+r) >> 1;
	if(u <= mid) get(node << 1, l, mid, u, v, res);
	if(mid + 1 <= v) get(node << 1|1, mid + 1, r, u, v, res);
}



signed main() {
	fast_cin();
	cin >> n;
	
	
	
	for(int i=1;i<=(int)1e6;++i) p[i] = i;
	
	
	for(int i=2;i<=100;++i) {
		if(p[i] == i) {
			for(int j=i*i;j <=(int)1e6;j += i) p[j] = min(p[j], i);
		}
	}
	
	
	for(int i=1;i<=n;++i) {
		int x;
		cin >> x;
		vector<bool> tmp(105,0);
		factor(tmp, x);
		a[i] = tmp;
	}
	build(1,1,n);
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;++i) {
		int t,u,v;
		cin >> t >> u >> v;
		/*
		for(int j=2;j<=100;++j) cout << st[1][j];
		cout << "\n";
		*/
		if(t==1) {
			vector<bool> res(105,0);
			bool good = 1;
			get(1,1,n,u,v,res);
			
			for(int j=2;j<=100;++j) {
				good &= (res[j] == 0);
			}
			
			cout << (good ? "YES\n" : "NO\n");
		}
		
		else  {
			update(1,1,n,u,v);
		}
	}

	
	
	
	

	#ifndef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
	#endif
	
	return 0;
}
