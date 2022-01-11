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

int n;
int a[105];
int visited[105];
bool found = 0;
int ed = 0;
vector<int> res;

void dfs(int pos) {
	if(found) return;
	bool ok = 1;
	for(int i=1;i<=n;++i) ok &= (visited[i] != 0);
	if(ok) {
		while(visited[pos] != pos) {
			res.push_back(a[pos]);
			pos = visited[pos];
		}
		res.push_back(a[pos]);
		reverse(res.begin(),res.end());
		found = 1;
		return;
	}
	for(int i=1;i<=n;++i) {
		if(!visited[i] && (a[i] == a[pos]*2 || (a[pos]%3==0 && a[pos]/3 == a[i]))) {
			visited[i] = pos;
			dfs(i);
			visited[i] = 0;
		}
	}
} 

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}
	
	for(int i=1;i<=n;++i) {
		visited[i] = i;
		dfs(i);
		if(found) {
			for(auto x : res) cout << x << " ";
			exit(0);
		}
		visited[i] = 0;
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}