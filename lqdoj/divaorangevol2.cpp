#include<bits/stdc++.h>

using namespace std;

int main() {
    long long a,b,aver;
    cin >> a >> b;
    if((a-b)%2 == 0) {
        if (a==b) {
            cout << "YES";
            return 0;
        }
        else {
            aver = (a+b)/2;
            if(((aver<a)&&(aver>b)) || ((aver>a)&&(aver<b))) {
                cout << "YES";
                return 0;
            }
            else cout << "NO";
        }
    }
    else cout << "NO";
}
