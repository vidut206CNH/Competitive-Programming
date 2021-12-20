#include<bits/stdc++.h>

using namespace std;

int main() {
    int m,n;
    cin >> m >> n;
    long long Max;
    long long a[m][n];
    long long res[m][n];
    vector<long long> sumc(n,0),sumr(m,0),crossr(m+n-1,0),crossc(m+n-1,0);
    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            cin >> a[i][j];
            sumr[i] += a[i][j];
            sumc[j] += a[i][j];
            crossr[i-j+n-1] += a[i][j];
            crossc[i+j] += a[i][j];
        }
    }
    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            long long temp = sumr[i] + sumc[j] + crossr[i-j+n-1] + crossc[i+j] - 3*a[i][j];
            cout << temp << '\n';
        }
    }
}
