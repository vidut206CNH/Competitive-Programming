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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,b;
int a[105];
int odd[105];
int even[105];
int dp[105];
int cost[105];
int cnt[105];

signed main() {
	fast_cin();
	
	cin >> n >> b;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		odd[i] = odd[i-1] + (a[i]%2 != 0);
		even[i] = even[i-1] + (a[i]%2==0);
	}
	
	vector<int> p;
	
	for(int i=1;i<n;++i) {
		if(odd[i] == even[i]) {
			cost[i] = abs(a[i] - a[i+1]);
			p.push_back(cost[i]);
		}
	}
	sort(p.begin(),p.end());
	int id = 0;
	int sum = 0;
	
	while(id < (int)p.size() && sum + p[id] <= b) {
		sum += p[id];
		id++;
	}
	cout << id;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}