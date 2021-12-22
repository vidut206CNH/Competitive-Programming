/* 
	Author : vidut_206_CNH
	Problem: https://codeforces.com/problemset/gymProblem/102986/E
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
const int MAXN1 = 1e5+5;
const int MAXN2 = 5e6+5;

int t;
bool p[MAXN2];
int g[MAXN2];
int cnt[MAXN2];
int f[MAXN2];

void pre_calc() {
	
	for(int i=2;i<=(int)5e6;++i) g[i] = i;
	
	for(int i=2;i*i<=(int)5e6;++i) {
		if(!p[i]) {
			for(int j=i*i;j <= (int)5e6;j += i) {
				p[j] = 1;
				while(g[j]%i==0) {
					g[j] /= i;
					cnt[j]++;
				}
			}
		}
	}
	for(int i=2;i<=(int)5e6;++i) {
		cnt[i] += (g[i] != 1);
		f[i] = f[i-1] + cnt[i]; 
	}
}



signed main() {
	fast_cin();
	pre_calc();
	cin >> t;
	
	while(t--) {
		int r,l;
		cin >> r >> l;
		cout << f[r] - f[l] << "\n";
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}