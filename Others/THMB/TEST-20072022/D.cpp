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

const long long MOD = 998244353;
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e5+5;

struct rec{
	int x, y, u, v;
};

int m,n,q;
rec Q[MAXN1];
int a[MAXN2];
int d[MAXN2];
long long sum[20][20];
long long f[MAXN2];
long long g[MAXN2];

void sub2() {
	for(int i = 1; i <= q; ++i) {
		int L = Q[i].y;
		int R = Q[i].v;
		
		d[L]++;
		d[R + 1]--;
		
		for(int pos = 1; pos <= n; ++pos) {
			a[pos] = a[pos - 1] + d[pos];
			f[pos] = f[pos - 1] + a[pos];
			g[pos] = g[pos - 1] + 1LL*pos*a[pos];
			//db(a[pos]);
		}
		
		//cerr << "\n";
		
		long long res = 1e18;
		for(int pos = 1; pos <= n; ++pos) {
			long long sum = 1LL*f[pos]*pos - g[pos];
			sum += ((g[n] - g[pos]) - 1LL*pos*(f[n] - f[pos]));
			res = min(res, sum); 	
		}
		
		cout << res%MOD << " ";
	}
}


void sub1() {
	for(int i = 1; i <= q; ++i) {
		int X = Q[i].x;
		int Y = Q[i].y;
		int U = Q[i].u;
		int V = Q[i].v;
		
		for(int r = X; r <= U; ++r) {
			for(int c = Y; c <= V; ++c) {
				sum[r][c]++;	
			}
		}
		
		long long res = 1e18;
		
		for(int x = 1; x <= m; ++x) {
			for(int y = 1; y <= n; ++y) {
				long long tmp = 0;
				for(int r = 1; r <= m; ++r) {
					for(int c = 1; c <= n; ++c) {
						tmp += (abs(x - r) + abs(y - c))*sum[r][c];
					}
				}
				res = min(res, tmp);
			}
		}
		
		cout << res%MOD << " ";	
	}
}

int main() {
	fast_cin();


/*	freopen("balls.inp", "r", stdin);
	freopen("balls.out", "w", stdout);*/
	int t;
	cin >> t;
	cin >> m >> n >> q;
	for(int i = 1; i <= q; ++i) {
		cin >> Q[i].x >> Q[i].u >> Q[i].y >> Q[i].v;
	}	
	if(t == 2) {
		sub2();			
	}
	
	if(t == 1) {
		sub1();
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}