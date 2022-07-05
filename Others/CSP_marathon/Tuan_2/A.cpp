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
int lf[MAXN1];
int a[MAXN1];
int bestL[MAXN1], bestR[MAXN1];
vector<pii> D[MAXN1];
long long P[25];
deque<int> q;

void calc(int pos) {
	if(a[pos] == 1) return;
	
	int p = lf[a[pos]];
	int cnt = 0;
	while(a[pos]%p == 0) {
		a[pos] /= p;
		cnt++;
	}
	
	D[p].push_back({pos, cnt});
	
	calc(pos);
	
}


long long power(long long A, long long B) {
	long long res = 1;
	while(B) {
		if(B&1) res = res*A%MOD;
		A = A*A%MOD;
		B /= 2;
	}
	
	return res;
}



int main() {
	fast_cin();
	
	for(int i = 2; i < MAXN1; ++i) lf[i] = i;
	
	for(int i = 2; i*i < MAXN1; ++i) {
		if(lf[i] != i) continue;
		for(int j = i*i; j < MAXN1; j += i) lf[j] = min(lf[j], i);
	}
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] == 0) {
			cout << 0;
			return 0;
		}
		calc(i);
	}
	
	long long res = 1;
	
	for(int val = 2; val < MAXN1; ++val) {
		if (sz(D[val]) == 0) continue;
		
		P[1] = val;
		for(int i = 2; i <= 20; ++i) {
			if(P[i - 1] > MAXN2/val) break;
			P[i] = P[i - 1]*val%MOD;
		}
		
		q.clear();
		
		for(int i = 0; i < sz(D[val]); ++i) {
			int x = D[val][i].se;
			
			while(!q.empty() && D[val][q.back()].se <= x) q.pop_back();
			
			if(!q.empty()) bestL[i] = D[val][q.back()].fi;
			else bestL[i] = 0;
			
			q.push_back(i);
		}
		
		q.clear();
		
		for(int i = sz(D[val]) - 1; i >= 0; --i) {
			int pos = D[val][i].fi;		
			int x = D[val][i].se;
			
			while(!q.empty() && D[val][q.back()].se < x) q.pop_back();
			
			if(!q.empty()) bestR[i] = D[val][q.back()].fi;
			else bestR[i] = n + 1;
			
			res = 1LL*power(P[x],(pos - bestL[i])*(bestR[i] - pos)%MOD)%MOD*res%MOD;
				
			q.push_back(i);
		}
		
	}
	
	cout << res;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}