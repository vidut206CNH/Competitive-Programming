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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
bool ok[20];

signed main() {
	fast_cin();
	
	cin >> n;
	int temp = n,finum = 0,s = 0;
	
	while(temp) {
		ok[temp%10] = 1;
		if(temp/10 == 0) finum = temp;
		temp /= 10;
		++s;
	}
	bool bad = 1;
	
	for(int i=0;i<=9;++i) {
		bad &= (ok[i]);
	}
	
	if(bad) {
		cout << "Impossible";
		exit(0);
	}
	
	int diff = n;
	vector<int> res = {0};
	
	for(int i=9;i>=1;--i) {
		if(s == 1) continue;
		if(ok[i]) continue;
		int sum = i;
		
		for(int num = 2;num <= s - 1;++num) {
			
			for(int d = 9;d >= 0; --d) {
				if(ok[d]) continue;
				
				sum = sum*10 + d;
				
				break;
			}
		}
		if(diff > abs(n - sum)) {
			diff =abs(n - sum);
			res.clear();
		}
		if(diff == abs(n - sum)) res.push_back(sum);
		break;
	}
	
	
	
	for(int i=finum-1;i>=1;--i) {
		
		if(ok[i]) continue;
		int sum = i;
		
		for(int num = 2;num <= s;++num) {
			
			for(int d = 9;d >= 0; --d) {
				if(ok[d]) continue;
				
				sum = sum*10 + d;
				
				break;
			}
		}
		if(diff > abs(n - sum)) {
			diff =abs(n - sum);
			res.clear();
		}
		if(diff == abs(n - sum)) res.push_back(sum);
	}
	
	for(int i=finum + 1; i<=9;++i) {
		
		if(ok[i]) continue;
		
		int sum = i;
		
		for(int num = 2; num <= s;++num) {
			for(int d=0;d <= 9;++d) {
				
				if(ok[d]) continue;
				
				sum = sum*10 + d;
				break;
			}
		}
		
		if(diff > abs(n - sum)) {
			diff =abs(n - sum);
			res.clear();
		}
		if(diff == abs(n - sum)) res.push_back(sum);
		
		break;
	}
	
	for(int i=1;i<=9;++i) {
		
		if(ok[i]) continue;
		int sum = i;
		
		for(int num = 2;num <= s+1; ++num) {
			for(int d=0;d <= 9;++d) {
				if(ok[d]) continue;
				sum = sum*10 + d;
				break;
			} 
		}
		
		if(diff > abs(n - sum)) {
			diff =abs(n - sum);
			res.clear();
		}
		if(diff == abs(n - sum)) res.push_back(sum);
		
		break;
	}
	
	sort(res.begin(),res.end());
	for(auto x : res)  cout << x << " ";
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}