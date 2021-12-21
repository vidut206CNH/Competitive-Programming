#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    string x;
    getline(cin, str);
    stringstream sstr(str);
    while(getline(sstr,x,',')) {
        cout << x << "\n";
    }
}
