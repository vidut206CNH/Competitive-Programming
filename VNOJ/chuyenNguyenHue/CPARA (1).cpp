#include<bits/stdc++.h>

using namespace std;

int m,n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("CPARA.INP", "r", stdin);
    //freopen("CPARA.OUT", "w", stdout);

    cin >> m >> n;
    ++m;
    ++n;
    long long res = 0;
    for(int r = 1; r <= m; ++r) {
        for(int c = 1; c <= n; ++c) {
			//cerr << r << " " << c << "\t";
			long long sum = 0;
	
            /// rect
            res += 1LL*(r - 1)*(c - 1);

            /// Oy duong cheo

           	sum += 2LL*min(c - 1, n - c)*(r)*(r - 1)/2;
			//cerr << sum << " ";
            /// Ox duong cheo

            sum += 2LL*min(r - 1, m - r)*(c)*(c - 1)/2;
            
            
            res += sum;
        }
    }

	//cout << res;
	
    for(int r = 1;r <= m; ++r) {
        for(int c = 1; c <= n; ++c) {
            //res -= 3LL*min({r - 1, m - r})*min({c - 1, n - c});
        }
    }

    cout << res;
}
