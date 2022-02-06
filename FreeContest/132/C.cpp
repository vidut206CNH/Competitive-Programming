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
const int MAXN1 = 1e6+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
int f[MAXN1];
int s[MAXN1];
int L[MAXN1], R[MAXN1];

signed main() {
	fast_cin();
	
	cin >> n;
	
	for(int i=1;i<=n;++i) cin >> a[i];
	
	for(int i=1;i<=n;++i) {
		if(i == 1) f[i] = a[i];
		else f[i] = max(f[i-1], a[i]);
	}
	
	for(int i=n;i>=1;--i) {
		if(i == n) s[i] = a[i];
		else s[i] = max(s[i + 1], a[i]);
	}
	int res = 0, best = 0;
	for(int i=1;i<=n;++i) {
		res += (min(f[i], s[i]) - a[i]);
	}
	
	deque<int> d;
	
	for(int i=1;i<=n;++i) {
		while(!d.empty() && a[d.back()] <= a[i]) d.pop_back();
		if(!d.empty()) L[i] = d.back();
		else L[i] = i;
		d.push_back(i);
	}
	
	while(!d.empty()) d.pop_back();
	
	for(int i=n;i>=1;--i) {
		while(!d.empty() && a[d.back()] <= a[i]) d.pop_back();
		if(!d.empty()) R[i] = d.back();
		else R[i] = i;
		d.push_back(i);
	}
	
	for(int i=1;i<=n;++i) {
		int l = L[i];
		int r = R[i];
		if(a[i] < a[l] && a[i] < a[r]) continue;
		if(a[i] >= a[l] && a[i] < a[r]) {
			best = max(best, r - i - 1);
		}
		if(a[i] >= a[r] && a[i] < a[l]) {
			best = max(best, i - l - 1);
		}
/*		db(best);
		db(i);
		cerr << "\n";*/
	}
	
//	cout << res << "\n";
	cout << res + best;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}