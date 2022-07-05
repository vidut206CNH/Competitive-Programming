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

int n;
long long k;
int a[MAXN1];
int cnt[MAXN1];

int main() {
	fast_cin();
	
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	vector<int> p;
	
	for(int i = 1; i <= n; ++i) {
		if(k%a[i] == 0) {
			p.push_back(a[i]);
			cnt[a[i]]++;
		}
	}
	
	p.resize(unique(p.begin(), p.end()) - p.begin());
	
	long long res = 0;
	
	for(int i = 0; i < sz(p); ++i) {
		for(int j = i; j < sz(p); ++j) {
			long long val = p[i]*p[j];
			if(k%val) continue;
			if(k/val < p[j]) continue;
			
			if(i == j) {
				if(k == 1LL*p[i]*val) {
					res += 1LL*cnt[p[i]]*(cnt[p[i]] - 1)*(cnt[p[i]] - 2)/6;
				}
				
				else res += 1LL*cnt[k/val]*cnt[p[i]]*(cnt[p[i]] - 1)/2;
			}
			
			else {
				if(p[j] == k/val) {
					res += 1LL*cnt[p[i]]*cnt[p[j]]*(cnt[p[j]] - 1)/2;
				}
				
				else res += 1LL*cnt[p[i]]*cnt[p[j]]*cnt[k/val];
			}
		}
	}
	
	
	cout << res;
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}