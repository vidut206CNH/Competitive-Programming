#include<bits/stdc++.h>

using namespace std;

int sumdiv(int a) {
    int sum=0;
    for(int i=1;i<=sqrt(a);++i) {
        if(a%i==0) {
            if(i*i == a) sum += i;
            else sum += (i + a/i);
        }
    }
    return sum-a;
}


int main() {
    int a,b;
    cin >> a >> b;
    if(sumdiv(a)==b && sumdiv(b)==a) cout << "YES";
    else cout << "NO";




}
