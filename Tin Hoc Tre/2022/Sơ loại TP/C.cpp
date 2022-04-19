/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int inf = 1e9 + 7;

int n;
string a[105];
bool choose[105];
int X[105];
int ans = inf;
string sans = "";

void sub2() {
}


void call(int pos) {
	if(pos == n + 1) {
		
		string s = a[X[1]];
		
		for(int i = 2; i <= n; ++i) {
			int low = 0, high = sz(a[X[i]]);
			int res = 0;
			while(low <= high) {
				int mid = (low + high) >> 1;
				string d1 = s.substr(sz(s) - mid, mid);
				string d2 = a[X[i]].substr(0, mid);
				
				if(d1 == d2) {
					res = mid;
					low = mid + 1;
				}
				else high = mid - 1;
			}
			
			s += a[X[i]].substr(res, sz(a[X[i]]) - res);
		}
		if(ans > sz(s)) {
			ans = sz(s);
			sans = s;
		}
		return;
	}
	
	
	for(int next = 1; next <= n; ++next) {
		if(choose[next] == false) {
			
			choose[next] = true;
			X[pos] = next;
			call(pos + 1);
			choose[next] = false;
		}
	}
}

void sub1() {
	
	for(int i = 1; i <= n; ++i) {
		X[1] = i;
		choose[i] = true;
		call(2);
	}
	
	cout << sans;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	if(n <= 10) {
		
		sub1();
		
	}
	
	else {
		for(int i = 1; i <= n; ++i) {
			int low = 0, high = min(sz(sans), sz(a[i]));
			int best_pos = 0;
			while(low <= high) {
				int mid = (low + high) >> 1;
				string d1 = sans.substr(sz(sans) - mid, mid);
				string d2 = a[i].substr(0, mid);
			
				if(d1 == d2) {
					best_pos = mid;
					low = mid + 1;
				}
				else high = mid - 1;
			}
		
			sans += a[i].substr(best_pos, sz(a[i]) - best_pos);
		}
		
		cout << sans;
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}
