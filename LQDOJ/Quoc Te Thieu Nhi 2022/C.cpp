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


struct DSU{
	vector<int> e;
	
	DSU(int n) {e = vector<int>(n + 1, -1); }
	
	int get(int u) {
		return (e[u] < 0 ? u : e[u] = get(e[u]));
	}
	
	int size(int u) {
		return -e[get(u)];
	}
	
	bool unite(int a, int b) {
		a = get(a);
		b = get(b);
		if(a == b) return false;
		
		if(e[a] > e[b]) swap(a, b);
		e[a] += e[b];
		e[b] = a;
		return true;
		
	}
};

int n,d;

int main() {
	fast_cin();
	
	cin >> n >> d;
	DSU dsu(n);
	long long res = 0;
	for(int i = 1; i <= d; ++i) {
		int x,y;
		cin >> x >> y;
		dsu.unite(x, y);
		if(dsu.size(x) > res) {
			res = dsu.size(x);
		}
		
		cout << res - 1 << "\n";
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}