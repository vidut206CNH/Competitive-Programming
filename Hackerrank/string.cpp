#include<bits/stdc++.h>

using namespace std;

int main() {
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    cout << a.size() << " " << b.size() << "\n";
    string c = a+b;
    cout << c << "\n";
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b;

}


