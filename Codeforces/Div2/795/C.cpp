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

int t,n,k;

int main() {
	fast_cin();
	
	cin >> t;
	while(t--) {
		cin >> n >> k;
		string s;
		cin >> s;
		int first = -1, last = -1;
		int cnt = 0;
		
		for(auto x : s) cnt += (x == '1');
		
		for(int i = 0; i < sz(s); ++i) {
			if(s[i] == '1') {
				first = i;
				break;	
			}
		}
		
		for(int i = sz(s) - 1;i >= 0; --i) {
			if(s[i] == '1') {
				last = sz(s) - 1 - i;
				break;
			}
		}
		
		if(cnt == 0) {
			cout << 0 << "\n";
			continue;
		} 
		
		long long sum = 0;
		for(int i = 0; i < sz(s); ++i) {
			if(s[i] != '1') continue;
			if(i != 0) sum++;
			if(i != sz(s) - 1) sum += 10;
		}
		
		if(cnt == 1) {
			if(last && last <= k) {
				cout << sum - (last == n - 1 ? 9 : 10) << "\n";
				continue;
			}
			
			if(last == 0) {
				cout << sum << "\n";
				continue;
			}
			
			else if (first && first <= k) {
				cout << sum - 1 << "\n";
				continue;
			}
			
			else {
				cout << sum << "\n";
				continue;
			}
		}
		
		else {
			if(last && last <= k) {
				sum -= 10;
				k -= last;
			}
			
			if(first && first <= k) {
				sum--;
				k -= first;
			}
			
			cout << sum << "\n";
		}
		
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}