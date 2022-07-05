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

int n;
char a[MAXN1];
char b[MAXN1];
deque<int> D[30];
int c[MAXN1];
int BIT[MAXN1];

void update(int pos) {
	for(;pos > 0; pos -= (pos & -pos)) BIT[pos]++;
}

int get(int pos) {
	int res = 0;
	for(;pos <= n; pos += (pos & -pos)) res += BIT[pos];
	return res;
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[n - i + 1] = a[i];
		D[a[i] - 'a'].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i) {
		c[i] = D[b[i] - 'a'].front();
		D[b[i] - 'a'].pop_front();
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		res += get(c[i]);
		update(c[i]);
	}
	
	cout << res;
	
	
		
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}