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

const long long MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;

int n,m;
int pos[MAXN1], neg[MAXN1];
vector<int> cntn, cntp, cntc;
long long po[MAXN1];

int ls(int x) {return (1 << x);}


void calc(vector<int> & D) {
	reverse(D.begin(), D.end());
	
	for(int i = 0; i < m; ++i) {
		for(int mask = 0; mask < (1 << m); ++mask) {
			if(mask >> i & 1) {
				D[mask] += D[(mask ^ (1 << i))];
			}
		}
	}
	
	reverse(D.begin(), D.end());
}

int main() {
	fast_cin();
	
	cin >> n >> m;
	cntp.resize(ls(m));
	cntn.resize(ls(m));
	cntc.resize(ls(m));
	
	po[0] = 1;
	for(int i = 1; i <= n; ++i) po[i] = po[i - 1]*2%MOD;
	
	for(int i = 1; i <= m; ++i) {
		int t; 
		cin >> t;
		while(t--) {
			int x;
			cin >> x;
			if(x < 0) neg[-x] |= (1 << (i - 1));
			else pos[x] |= (1 << (i - 1));
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		neg[i] = (ls(m) - 1)^neg[i];
		pos[i] = (ls(m) - 1)^pos[i];
		cntp[pos[i]]++;
		cntn[neg[i]]++;
		cntc[pos[i] & neg[i]]++;
	}
	
	calc(cntp);	
	calc(cntn);
	calc(cntc);
	
	// 
	long long res = 0;
	
	for(int mask = 0; mask < (1 << m); ++mask) {
		int posi = n - cntp[mask];
		int nega = n - cntn[mask];
		int comm = posi + nega - (n - cntc[mask]);
		if(comm == 0) {
			long long cur = po[n - posi - nega];
			if(__builtin_popcount(mask) % 2) {
				res = (res - cur + MOD)%MOD;
			}
			
			else res = (res + cur)%MOD;
		}
		
		//db(res);
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}