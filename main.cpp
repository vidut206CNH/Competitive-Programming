#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

signed main() {
    fastio
    ll n;
    cin >> n;
    int res = 0;
    for (int i = 1;i * i * i <= n;i++) {
        for (int j = i + 1;j * j <= n;j++) {
            int c = n / (i * j);
            if (c > j) res = res + (c - j)*6;
        }
    }
    for(int i = 1; i*i <= n; ++i) {
          int c = n/(i*i);
         if(c >= i) res++;
          if(c >= i) res = res + (c - i)*3;
          res = res + min(i - 1, c)*3;
    }
    cout << res;

    return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ