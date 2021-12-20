/* 
	link problem: 
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
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e6+5;
const int MAXN2 = 2e5 + 5;

int ans = 0;
string s;

bool cmp(const string &a, const string &b) {
	if(a[0] == '0') return 0;
	if(a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

void backtrack(string num, int sum,int cur, int &k,int &val) {
	if(sum + 9*(k-cur + 1) < val) return;
	if(sum > val) return;
	if(num[0] == '0') return;
	if(cur > k) return;
	if(sum == val) {
		if(!cmp(num, s)) return;
		ans++;
		//cout << num << " ";
	}
	for(int i=0;i<=9;++i) {
		if(sum+i <= val) {
			backtrack(num + char('0' + i), sum + i, cur+1,k, val);
			//cout << num << " " << cur << "\n";
		}
	}
	
}

void sol1() {
	cin >> s;
	if(s=="0") {
	    cout << 0;
	    return;
	}
	int sum = 0,n = s.size();
	for(auto x : s) sum += (x - '0');
	backtrack("", 0, 0, n, sum);
	cout << ans;
}


signed main() {
	fast_cin();
	sol1();
	
	return 0;
}