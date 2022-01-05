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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;
const int base = (int)'a' - 1;

unordered_map<int,int> E[26];
int n,k;
char res[MAXN1];
int last[27];

signed main() {
	fast_cin();
	
	cin >> n >> k;
	int cur = 1;
	res[1] = 'a';
	for(int i=1;i<=26;++i) last[i] = i;
	
	for(int i=2;i <= n;++i) {
		int next = last[cur];
		last[cur]++;
		if(last[cur] > k) last[cur] = 1;
		cur = next;
		res[i] = char(cur + 'a' - 1);
	}
	for(int i=1;i<=n;++i) cout << res[i];
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}