#include<bits/stdc++.h>

using namespace std;

int fmax(int a, int b) {
    int max = a;
    if (b>a) max = b;
    return max;
}
int main() {
    long long n;
    cin >> n;
    int vmax=1,k;
    while(n != 0)  {
        k = n%10;
        n /= 10;
        vmax = fmax(vmax,k);
    }
    cout << vmax;
}
