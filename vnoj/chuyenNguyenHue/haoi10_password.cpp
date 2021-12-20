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
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int ch1[nMax],ch2[nMax],ch3[nMax],ans=0;
string s;

int bins(int r,int a,int b, int c) {
	int l =1, ans = -1,mid;
	while(l<=r) {
		mid = (l+r)/2;
		if(a-ch1[mid-1] < 1 || b-ch2[mid-1] < 1 || c-ch3[mid-1] < 1) {
			r = mid-1;
		}
		else {
			ans = max(ans,mid);
			l = mid + 1;
		}
	}
	return ans;
	
}

void solve() {
	cin >> s;
	for(int i=0;i<s.size();++i) {
		ch1[i+1] = ch1[i];
		ch2[i+1] = ch2[i];
		ch3[i+1] = ch3[i];
		if(s[i] >= '0' && s[i] <= '9') ch1[i+1]++;
		else if(s[i] >= 'a' && s[i] <= 'z') ch2[i+1]++;
		else ch3[i+1]++;
	}
	for(int i=6;i<=s.size();++i) {
		int t = bins(i-6+1,ch1[i],ch2[i],ch3[i]);
		//cout << t << ' ';
		if(t!=-1) {
			ans += t;
		}
		//cout << ans << '\n';
	}
	cout << ans;
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}