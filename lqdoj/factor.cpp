#include<bits/stdc++.h>

using namespace std;

void cntfac(long long n) {
    long long cnt=2;
    for(long long i=2;i<=sqrt(n);++i) {
        if(n%i==0) {
            if(i*i==n) cnt++;
            else cnt += 2;
        }
    }
    cout << cnt;
}

void primeFactors(long long n)
{
    while (n % 2 == 0 && n>2)
    {
        cout << 2 << '*';
        n = n/2;
    }

    for (long long i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0 && n>i)
        {
            cout << i << '*';
            n = n/i;
        }
    }
    if (n >= 2) {
        cout << n;
    }
}

int main() {
    long long n;
    cin >> n;
    primeFactors(n);
    cout << '\n';
    cntfac(n);
}
