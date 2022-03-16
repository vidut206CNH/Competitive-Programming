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

int t,M;

struct state{
	pii left, mid, right;
};

pii add(const pii &A, const pii &B) {
	return {(A.fi + B.fi)%M, (A.se + B.se)%M};
}

signed main() {
	fast_cin();
	
	
	cin >> t >> M;
	vector<int> bits;
	while(t) {
		bits.push_back(t&1);
		t >>= 1;
	}
	reverse(bits.begin(),bits.end());
	state ans = {{0, 1}, {1, 1}, {1, 0}};
	for(int i = 1; i < sz(bits); ++i) {
		state next;
		if(bits[i] == 0) {
			next.left = ans.left;
			next.mid = add(ans.mid, ans.left);
			next.right = ans.mid;
		}
		else {
			next.right = ans.right;
			next.mid = add(ans.mid, ans.right);
			next.left = ans.mid;
		}
		
		ans = next;
	}
	
	cout << ans.mid.fi << " " << ans.mid.se;	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}