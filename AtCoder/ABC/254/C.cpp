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
const int MAXN1 = 2e5+5;
const int MAXN2 = 1e6+5;

int n,k;
int a[MAXN1];
int res[MAXN1];
bool visited[MAXN1];
int main() {
	fast_cin();
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		if(visited[i]) continue;
		vector<int> p;
		for(int j = i; j <= n; j += k) p.push_back(a[j]);
		sort(p.begin(), p.end());
		int pos = i;
		for(auto x : p) {
			res[pos] = x;
			visited[pos] = true;
			pos += k;
		}
	}
	
	bool good = true;
	for(int i = 1; i < n; ++i) {
		good &= (res[i] <= res[i + 1]);
	}
	
	cout << (good ?  "Yes\n" : "No\n");
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}