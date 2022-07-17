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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int C = 3600;
int n;
int a[MAXN1];

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	priority_queue<int, vector<int>, greater<> > pq;
	
	sort(a + 1, a + n + 1, greater<>());
	long long res = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == 1) {
			res += a[i];
			pq.push(2);
			continue;
		}
		
		if(a[i]*pq.top() > a[i] + C) {
			res += a[i] + C;
			pq.push(2);
		}
		
		else {
			int m = pq.top();
			pq.pop();
			
			res += 1LL*a[i]*m;
			pq.push((m << 1));
		}
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}