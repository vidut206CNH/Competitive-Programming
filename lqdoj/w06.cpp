#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    int r = a%b;
    while (r != 0) {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}


int main() {
    int m,n;
    cin >> m >> n;
    int gcdv = gcd(m,n);
    vector<int> vec;
    for (int i=1;i<= sqrt(gcdv);++i) {
        if (gcdv%i == 0) {
            if (gcdv/i == i) {
                vec.push_back(i);
            }
            else {
                vec.push_back(i);
                vec.push_back(gcdv/i);
            }
        }
    }
    sort(vec.begin(),vec.end());
    for (int i=0;i<vec.size();++i) {
        cout << vec[i] << " ";
    }
}
