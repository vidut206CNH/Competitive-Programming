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
char res[MAXN1];


int main() {
	fast_cin();
	
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if((int)res[i] != 0) continue;
		
		cout << "? 1 " << i << endl;
		cnt++;
		char c;
		cin >> c;
		int pos = i;
		while(pos <= n) {
			
			res[pos] = c;
			int low = pos + 1, high = n - 1, best = n + 1;
			while(low <= high) {
				int mid = (low + high) >> 1;
				int X,Y,Z, T;
				cout << "? 2 " << pos << " " << mid << endl;
				cin >> X;
				cout << "? 2 " << pos + 1 << " " << mid << endl;
				cin >> Y;
				
				if(X == Y) {
					high = mid - 1;
					continue;
				}
				
				cout << "? 2 " << pos << " " << mid + 1 << endl;
				cin >> Z; 
				cout << "? 2 " << pos + 1 << " " << mid + 1 << endl;
				cin >> T;
				
				
				if(X > Y && X == Z && X == T) {
					best = mid + 1;
					break;
				}
				
				else {
					low = mid + 1;
				}
			}
			
			pos = best;
			
		}
	}
	
	
	cout << "! ";
	for(int i = 1; i <= n; ++i) cout << res[i];
	cout << cnt;
	cout << endl;
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}