#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool chk1 = false;
    vector<int> vec;
    int x,a = s.size(),sum=0;
    for(int i=0;i<a;++i) {
        x = (int)(s[i]) - 48;
        sum = (sum+x)%3;
        vec.push_back(x);
        if (x == 0) chk1 = true;
    }
    if((chk1) && (sum==0)) {
        sort(vec.begin(),vec.end(),greater<int>());
        for(auto x : vec) cout << x;
    }
    else {
        cout << -1;
    }

}
