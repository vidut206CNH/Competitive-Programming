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

long long L,n;

int main() {
	fast_cin();
	
	freopen("PARTITION.INP", "r", stdin);
	freopen("PARTITION.OUT", "w", stdout);
	
	cin >> L >> n;
	long long res = 0, sum = 0;
	priority_queue<long long, vector<long long>, greater<> > pq;
	for(int i = 1; i <= n; ++i) {
		long long x;
		cin >> x;
		sum += x;
		pq.push(x);
	}
	
	if(L != sum) pq.push(L - sum);
	
	while(sz(pq) != 1) {
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();
		res += (x + y);
		pq.push(x + y);
	}
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}