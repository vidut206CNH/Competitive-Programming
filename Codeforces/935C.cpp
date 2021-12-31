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
const double eps = 1e-9;

double dist(const double xA, const double yA, const double xB, const double yB) {
	return sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
}


double R,x_1,y_1,x_2,y_2;

signed main() {
	fast_cin();
	
	
	cin >> R >> x_1 >> y_1 >> x_2 >> y_2;
	
	if(dist(x_1,y_1,x_2,y_2) - R > eps) {
		cout << x_1 << " " << y_1 << " " << R;
		return 0;
	}
	if(dist(x_1,y_1,x_2,y_2) == (double)0.0) {
		cout << fixed << setprecision(15) <<  x_1 << " " << y_1 + R/2 << " " << R/2;
		return 0;
	}
	double r = (dist(x_1,y_1,x_2,y_2) + R)/2;
	double d_x = r/dist(x_1,y_1,x_2,y_2)*abs(x_1 - x_2);
	double d_y = r/dist(x_1,y_1,x_2,y_2)*abs(y_1 - y_2);
	if(x_2 > x_1) d_x = x_2 - d_x;
	else d_x = x_2 + d_x;
	if(y_2 > y_1) d_y = y_2 - d_y;
	else d_y = y_2 + d_y;
	
	cout << fixed << setprecision(15) << d_x << " " << d_y << " " << r; 
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}