#include<bits/stdc++.h>

using namespace std;

int ac[100];

int main() {
    int n,x;
    cin >> n;
    while(n>0) {
        cin >> x;
        ac[x] += 1;
        --n;
    }
    for(int i=0;i<100;++i) {
        if(ac[i]!= 0) {
            while(ac[i]>0) {
                cout << i << ' ';
                ac[i] = ac[i] - 1;
            }
        }
    }

}
