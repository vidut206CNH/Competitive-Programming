#include<iostream>

using namespace std;

long MAX(long a,long b, long c) {
    long MAX = a;
    if (b>MAX) {
        MAX = b;
    }
    if (c>MAX) {
        MAX = c;
    }
    return MAX;
}

int main() {
    long a,b,c;
    cin >> a >> b >> c;
    cout << MAX(a,b,c);
}
