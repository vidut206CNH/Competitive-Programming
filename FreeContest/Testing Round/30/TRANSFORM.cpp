#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MOD = (int)1e9 + 9;

int n, k, m, c[MAXN][MAXN];
long long dp[MAXN][MAXN];
char s[MAXN], t[MAXN];

int main() {
    c[0][0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
    }

    while (scanf("%d%d%d", &n, &k, &m) != EOF) {
        scanf("%s", s);
        scanf("%s", t);

        int cntSame = 0;
        for(int i = 0; i < n; ++i)
            cntSame += (s[i] == t[i]);

        for(int i = 0; i <= k; ++i)
            for(int j = 0; j <= n; ++j)
                dp[i][j] = 0;

        dp[0][cntSame] = 1;
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j <= n; ++j) {
                for(int x = 0; x <= min(j, m); ++x) {
                    int J = j - x + (m - x);
                    dp[i+1][J] = (dp[i+1][J] + (dp[i][j] * c[j][x])%MOD * c[n-j][m-x]) % MOD;
                }
            }
        }

        printf("%lld\n", dp[k][n]);
    }

    return 0;
}
