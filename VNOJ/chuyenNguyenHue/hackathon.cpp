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
const int MAXN1 = 3e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int m,n,p, k;
int A[MAXN1];
int B[MAXN1];
int C[MAXN1];
int id[MAXN1];
int besta[MAXN1];
int bestb[MAXN1];

signed main() {
	fast_cin();

	cin >> m >> n >> p;
	k = m + n + p;
	int sumc = 0;
	for(int i = 1; i <= k; ++i) {
		cin >> A[i] >> B[i] >> C[i];
		sumc += C[i];
		A[i] -= C[i];
		B[i] -= C[i];
		id[i] = i;
	}
	
	
	sort(id + 1, id + k + 1, [&](const int &i, const int &j) {
		return A[i] - B[i] < A[j] - B[j];
	});
	
	int suma = 0, sumb = 0;
	priority_queue<int> pa, pb;
	
	for(int i = 1; i <= k; ++i) {
		suma += A[id[i]];
		pa.push(A[id[i]]);
		if(sz(pa) > m) {
			suma -= pa.top();
			pa.pop();
		}
		
		besta[i] = suma;
	}
	
	
	for(int i = k; i >= 1; --i) {
		sumb += B[id[i]];
		pb.push(B[id[i]]);
		if(sz(pb) > n) {
			sumb -= pb.top();
			pb.pop();
		}
		
		bestb[i] = sumb;
	}
	
	int res = inf;
	for(int i = m; i <= k - n; ++i) {
		res = min(res, besta[i] + bestb[i + 1] + sumc);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}