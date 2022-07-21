#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int nmax = 10001;

int f[nmax][19][8];

int dp(int i, int r, int s){
    if (i==-1) return r==0;
    auto& ans = f[i][r][s];
    if (ans) return ans-1;
    for (int j = 0; j < 10; ++j)
        if ((s>>(30-j)%3&1)==0)
            ans = (ans+dp(i-1, (r*10+j)%19, (j==0&&s==0)?0:(1<<j%3|s) )) % mod;
    return ans++;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        string L, R;
        cin >> L >> R;
        if (*min_element(R.begin(), R.end()) == '9'){//++R
            R = "1"+string(R.size(), '0');
        } else {
            for (int i = R.size(); i--; )
                if (R[i] != '9'){
                    ++R[i];
                    for (int j = i+1; j < R.size(); ++j) R[j] = 0;
                    break;
                }
        }
        auto cnt = [&](string R){
            int ans = 0;
            reverse(R.begin(), R.end());
            for (int i = R.size(), s = 0, r = 0; i--; ){
                int x = R[i] - '0';
                for (int j = 0; j < x; ++j)
                    if ((s>>(30-j)%3&1)==0)
                        ans = (ans+dp(i-1, (r*10+j)%19, (j==0&&s==0)?0:(1<<j%3|s) )) % mod;
                int j = x;
                if ((s>>(30-j)%3&1)==1) break;
                r = (r*10+j)%19, s = (j==0&&s==0)?0:(1<<j%3|s);
                
        		cerr << ans << "\n";
            }
            return ans;
        };
        cout << (cnt(R) + mod - cnt(L)) % mod << '\n';
    }
}
