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

string a[5];
int cnt[20];
int t[4];

signed main() {
	fast_cin();
	
	for(int i = 0; i < 5; ++i) cin >> a[i];
	
	
	for(int i = 0; i < 5; ++i) {
		if(a[i][0] <= '9' && a[i][0] >= '1') cnt[a[i][0] - '0']++;
		if(a[i][0] == 'T') cnt[10]++;
		if(a[i][0] == 'J') cnt[11]++;
		if(a[i][0] == 'Q') cnt[12]++;
		if(a[i][0] == 'K') cnt[13]++;
		if(a[i][0] == 'A') {
			cnt[1]++;
			cnt[14]++;
		}
		
		if(a[i].back() == 'H') t[0]++;
		if(a[i].back() == 'D') t[1]++;
		if(a[i].back() == 'C') t[2]++;
		if(a[i].back() == 'S') t[3]++;
	}
	
	int h2,h3,h4;
	h2 = h3 = h4 = 0;
	for(int i = 1; i<= 13; ++i) {
		h2 += (cnt[i] == 2);
		h3 += (cnt[i] == 3);
		h4 += (cnt[i] == 4);
	}
	
	bool sanh = false;
	
	for(int i = 1; i <= 10; ++i) {
		sanh |= (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4]);
	}
	
	bool thung = false;
	
	for(int i = 0; i < 4; ++i) {
		thung |= (t[i] == 5);
	}
	
	if(thung && sanh) {
		cout << "Thung pha sanh";
	}
	
	else if(h4) {
		cout << "Tu quy";
	}
	
	else if(h3 && h2) {
		cout << "Cu lu";
		exit(0);
	}
	else if(thung) {
		cout << "Thung";
	}
	
	else if(sanh) {
		cout << "Sanh";
	}
	
	else if(h3) {
		cout << "Sam";
	}
	
	else if(h2 == 2) {
		cout << "Thu";
	}
	
	else if(h2) cout << "Doi";
	
	else cout << "Mau thau";
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}