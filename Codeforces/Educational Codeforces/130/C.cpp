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

int t;
int n;
char a[MAXN1];
char b[MAXN1];
int f[MAXN1];
vector<int> posb1,posb2;

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		posb1.clear();
		posb2.clear();
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) cin >> b[i];
		bool bad = false;
		
		for(int i = 1; i <= n; ++i) {
			if(a[i] == 'c') {
				if(a[i] == b[i]) continue;
				else {
					int id = i;
					while(id > 1 && a[id - 1] == 'b' && a[id] != b[id]) {
						swap(a[id], a[id - 1]);
						--id;
					}
					
					if(a[id] != b[id]) {
						bad = true;
						break;
					}
				}
			}
		}
		
		for(int i = 1; i <= n; ++i) bad |= (b[i] == 'c' && a[i] != 'c');
		
		if(bad) {
			cout << "NO\n";
			continue;
		}
		
		for(int i = 1; i <= n; ++i) f[i] = f[i - 1] + (a[i] == 'c');
		for(int i = 1; i <= n; ++i) if(a[i] == 'b') posb1.push_back(i);
		for(int i = 1; i <= n; ++i) if(b[i] == 'b') posb2.push_back(i);
		
		if(sz(posb1) != sz(posb2)) {
			cout << "NO\n";
			continue;
		}
		
		
		for(int i = 0; i < sz(posb1); ++i) {
			bad |= (posb2[i] > posb1[i]);
			if(posb2[i] <= posb1[i]) {
				int r = posb1[i];
				int l = posb2[i];
				bad |= (f[r] - f[l - 1] > 0);
			}
		}
		
		cout << (bad ? "NO\n" : "YES\n");
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}