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
#define INF 2e18
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;



void calc(int color, int x1,int y1, int x2, int y2, int &black, int &white) {
	if(x1 > x2 || y1 > y2) return;	
	
	int area = (abs(x1 - x2) + 1)*(abs(y1 - y2) + 1),num = area/2;
	if(area%2) {
		if(color == 1 && (x1 + y1)%2 == 0) {
			num++;
		} else if((color==0 || color == 2) && (x1 + y1)%2) num++;
	}
	
	if(color) {
		black += num;
		white -= num;
	} else {
		black -= num;
		white += num;
	}
}


signed main() {
	fast_cin();
	
	
	int t;
	cin >> t;
	while(t--) {
		int m,n;
		cin >> m >> n;
		int x_1, x_2, x_3, x_4, y_1, y_2, y_3, y_4;
		
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cin >> x_3 >> y_3 >> x_4 >> y_4;
		
		// number of white and black cells
		int black,white;
		black = white = n*m/2;
		if(n*m%2) white++;
		
		//cout << black << " " << white << "\n";
		
		calc(0, x_1,y_1,x_2,y_2,black, white);	
		
		//cout << black << " " << white << "\n";
		
		calc(1, x_3, y_3, x_4, y_4, black, white);
		
		//cout << black << " " << white << "\n";
		/*
		int h = max(0LL, min(x_2, x_4) - max(x_3,x_1) + 1);
		int r = max(0LL, min(y_2, y_4) - max(y_3, y_1) + 1);
		black += h*r;
		white -= h*r;
		*/
		
		calc(2, max(x_1,x_3) , max(y_1, y_3), min(x_2, x_4), min(y_2,y_4), black, white);
		cout << white << " " << black << "\n";	
		 
	}
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}