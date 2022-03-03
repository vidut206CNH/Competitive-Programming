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

const int MOD = 1e9 + 5;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;
const int base = 31;

int lenA, lenB;
int a[MAXN2];
int b[MAXN2];
int p[MAXN2];

int hashA[MAXN2];
int hashB[MAXN2];

int get_hash(int f[], int l, int r) {
	return (f[r] - f[l - 1]*p[r - l + 1] + MOD*MOD)%MOD;
}


signed main() {
	fast_cin();
	
	cin >> lenA >> lenB;
	
	for(int i = 1; i <= lenA; ++i) {
		char c;
		cin >> c;
		a[i] = c - 'a' + 1;
	}
	for(int i = 1; i <= lenB; ++i) {
		char c;
		cin >> c;
		b[i] = c - 'a' + 1;
	}
	
	// calc pow
	p[0] = 1;
	for(int i = 1; i <= max(lenA, lenB); ++i) {
		p[i] = p[i - 1]*base%MOD;
	}
	
	// hashing
	for(int i = 1; i <= lenA; ++i) {
		hashA[i] = (hashA[i - 1]*base + a[i])%MOD;
/*		db(hashA[i]);
		cerr << "\n";*/
	}
	
	for(int i = 1; i <= lenB; ++i) {
		hashB[i] = (hashB[i - 1]*base + b[i])%MOD;
/*		db(hashB[i]);
		cerr << "\n";*/
	}
	
	int q;
	cin >> q;
	while(q--) {
		int lA, rA, lB, rB;
		cin >> lA >> rA  >> lB >> rB;
		int high = min(rA - lA, rB - lB), low = 0, res = -1;
		while(low <= high) {
			int mid = (low + high) >> 1;
			if(get_hash(hashA, lA, lA + mid) == get_hash(hashB, lB, lB + mid)) {
				low = mid + 1;
				res = mid;
			} else high = mid - 1;
		}
/*		db(res);
		cerr << "\n";*/
		if(res == min(rA - lA, rB - lB)) {
			if((rA - lA) != (rB - lB)) {
				cout << (rA - lA < rB - lB ? '<' : '>');
			} else cout << "=";
		} else {
			cout << (a[res + 1 + lA] < b[res + 1 + lB] ? "<" : ">");
		}
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}