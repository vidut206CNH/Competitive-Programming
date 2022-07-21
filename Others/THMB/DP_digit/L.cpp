#include<bits/stdc++.h>
using namespace std;
int save[40][16][4], N[40], H[4][40];

const int MOD = 1e9 + 7;

int dp(int i, int ok, int r){
    if (i == 33) return r==0 && !ok;
    auto&ans = save[i][ok][r];
    if (ans != -1) return ans;
    ans = 0;
    for (int a=0;a<2;++a)
        for(int b=0;b<2;++b)
            for(int c=0;c<2;++c){
                int d=(N[i]-r-a-b-c+6) % 2;
                int j = a+2*b+4*c+8*d;
                int okk = 0;
                for (int t=0;t<4;++t){
                    okk |= ((j>>t&1) > H[t][i]-(ok>>t&1)) << t;
                }
                ans = (ans + dp(i+1, okk, (r+a+b+c+d)/2)) % MOD;
            }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long sum = 0;
        for (int t = 0; t < 4; ++t){
            long long l, h;
            cin >> l >> h;
            h -= l;
            sum += l;
            for (int i = 0; i <= 32; ++i){
                H[t][i] = h>>i&1;
            }
        }
        long long n;
        cin >> n;
        n -= sum;
        for (int i = 0; i <= 32; ++i) N[i] = n>>i&1;
        memset(save, -1, sizeof(save));
        cout << dp(0, 0, 0) << '\n';
    }
}
