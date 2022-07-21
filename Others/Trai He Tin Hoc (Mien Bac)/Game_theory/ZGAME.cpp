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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e6+5;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r) {
	return l + rng() * 1LL * rng()%(r - l + 1);
}

int n;
bool a[MAXN1];
int cnt[2];
set<int> st[2];


void calc(int rep) {	
	
	cnt[rep%2] += ((a[rep]^1) - a[rep]);
	cnt[(rep - 1)%2] += ((a[rep - 1]^1) - a[rep - 1]);
	
	a[rep] ^= 1;
	a[rep - 1] ^= 1;
	
	st[rep&1].erase(rep);
	
	if(a[rep - 1]) st[(rep + 1)&1].insert(rep - 1);
	else st[(rep + 1)&1].erase(rep - 1);
	
}

int main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
		cnt[i%2] += a[i];
		if(a[i] == 1) st[i%2].insert(i);
		
	}
	
	if(cnt[0]%2 == cnt[1]%2 && cnt[1]%2 == 0) {
		
		cout << 0 << endl;
		int rep;
		cin >> rep;
		
		if(rep > 0) {
			cnt[rep%2]--;
			a[rep] ^= 1;
			st[rep&1].erase(rep);
		}
		else {
			calc(-rep);
		}
		
	}
	
	else {
		cout << 1 << endl;
	}
	
	
	while(true) {
		if(cnt[0]%2 == 0 && cnt[1]%2 == 1) {
			auto it = st[1].rbegin();
			cout << *it << endl;
			a[*it] = 0;
			cnt[1]--;
			st[1].erase(*it);	
		}
		
		else if(cnt[0]%2 == 1 && cnt[1]%2 == 0) {
			auto it = st[0].rbegin();
			cout << *it << endl;
			a[*it] = 0;
			cnt[0]--;
			st[0].erase(*it);
		}
		
		else {
			int d = max(*st[0].rbegin(), *st[1].rbegin());
			calc(d);
			
			cout << -d << endl;
		}
/*		db(cnt[0]);
		db(cnt[1]);
		cerr << "\n";*/
		if(cnt[1] == cnt[0] && !cnt[0]) break;
		
		int rep;
		cin >> rep;
		
		if(rep > 0) {
			cnt[rep%2]--;
			a[rep] ^= 1;
			st[rep%2].erase(rep);
		}
		
		else {
			calc(-rep);
		}
	}
	
	
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}