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

int n,x;
map<int, int> dist;

int ss(int val) {
	int cnt = 0;
	while(val) {
		cnt++;
		val /= 10;
	}
	
	return cnt;
}


signed main() {
	fast_cin();
	
	cin >> n >> x;
	dist[x] = 0;
	queue<int> q;
	q.push(x);
	
	int res = -1;
	
	while(!q.empty()) {
		int val = q.front();
		int cost = dist[val];
		q.pop();
		
		if(ss(val) > n) continue;
		if(ss(val) == n) {
			res = cost;
			break;
		}
		
		int mul = val;
		while(val) {
			int rem = val%10;
			val /= 10;
			if(rem == 0 || rem == 1) continue;
			int val1 = mul*rem;
			
			if(dist.count(val1) == 0) {
				dist[val1] = cost + 1;
				q.push(val1);
			}
			
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}