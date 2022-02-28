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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
pii a[MAXN1];
pii b[MAXN1];
int bit[MAXN1];


void update(int val) {
	for(;val > 0; val -= (val & -val)) {
		bit[val]++;
	}
}

int get(int val) {
	int res = 0;
	for(;val < MAXN1; val += (val & -val)) {
		res += bit[val];
	}
	
	return res;
}



signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	
	for(int i = 1; i <= n; ++i) {
		cin >> b[i].fi;
		b[i].se = i;
	}
	
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	
	bool same = true;
	bool ndis = false;
	for(int i = 1; i <= n; ++i) same &= (a[i].fi == b[i].fi);
	for(int i = 1; i < n; ++i) ndis |= (a[i].fi == a[i + 1].fi);
	if(!same) {
		cout << "No";
		exit(0);
	}
	
	if(ndis) {
		cout << "Yes";
		exit(0);
	}
	
	sort(a + 1, a + n + 1, [&](const pii A, const pii B){
		return A.se < B.se;
	});
	
	sort(b + 1, b + n + 1, [&](const pii A, const pii B){
		return A.se < B.se;
	}); 
	
	//count inversion numbers
	
	int ca = 0, cb = 0;
	for(int i = 1; i <= n; ++i) {
		int val = a[i].fi;
		update(val);
		ca = (ca + get(val))%2;
	}
	
	memset(bit, 0, sizeof bit);
	
	for(int i = 1; i <= n; ++i) {
		int val = b[i].fi;
		update(val);
		cb = (cb + get(val))%2;
	}
	
	
	cout << (ca == cb ? "Yes" : "No");
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}