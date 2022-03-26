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
	
	
	struct node{
		pii left, mid, right;
	};
	
	int n,M;
	
	pii add(const pii &A, const pii & B) {
		return {(A.fi + B.fi)%M, (A.se + B.se)%M};
	}
	
	pii mul(pii A, int val) {
		pii res = {0, 0};
		while(val) {
			if(val&1) res = add(res, A);
			A = add(A, A);
			val /= 2;
		}
		
		return res;
	}
	
	void move_right(node &res, int val) {
		node d = res;
		d.right = res.right;
		d.mid = add(res.mid, mul(res.right, val));
		d.left = add(res.mid, mul(res.right, val - 1));
		res = d;
	}
	
	
	void move_left(node &res, int val) {
		node d = res;
		d.left = res.left;
		d.mid = add(res.mid , mul(res.left, val));
		d.right = add(res.mid, mul(res.left, val - 1));
		res = d;
	}
	
	signed main() {
		fast_cin();
		
		cin >> n >> M;
		node res = {{0, 1}, {1, 1}, {1, 0}};
		for(int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if(i&1) {
				move_right(res, x);
			} else move_left(res, x);
		}
		
		cout << res.mid.fi << " " << res.mid.se;
		
		
		#ifndef LOCAL_DEFINE
	    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
	    #endif
		
		return 0;
	}