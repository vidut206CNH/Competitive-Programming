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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r) {
	return l + rng() * 1LL * rng()%(r - l + 1);
}

int n;
int a[MAXN1];

int main() {
	fast_cin();
	
	cin >> n;
	int Nim = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		Nim ^= a[i];
	}
	
	if(Nim == 0) {
		cout << 0 << endl;
		int pos, val;
		cin >> pos >> val;
		a[pos] -= val;
	}
	
	else cout << 1 << endl;
	
	Nim = 0;
	set<int> st;
	
	for(int i = 1; i <= n; ++i) {
		Nim ^= a[i];
		if(a[i] != 0) st.insert(i); 
	}
	
	while(true) {
		for(auto pos : st) {
			
			int new_val = Nim^a[pos];
			if(new_val >= 0 && new_val <= a[pos]) {
				
				cout << pos << " " << a[pos] - new_val << endl;
								
				Nim = (Nim ^ a[pos] ^ new_val);
				
				a[pos] = new_val;
				
				if(a[pos] == 0) st.erase(pos);
				
				break;
 			}
		}
		
		if(!sz(st)) break;
		
		
		
		int pos,val;
		cin >> pos >> val;
		
		int new_val = a[pos] - val;
		Nim = (Nim ^ a[pos] ^ new_val);
		a[pos] = new_val;
		if(a[pos] == 0) st.erase(pos);
	}
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}