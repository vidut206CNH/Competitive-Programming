#include<bits/stdc++.h>

using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> a(150,0), b(150,0);
    int cnt=0;
    for(int i=0;i<s1.size();++i) {
        a[(int)s1[i]]++;
    }
    for(int i=0;i<s2.size();++i) {
        b[(int)s2[i]]++;
    }
    for(int i = 'a';i<='z';++i) {
        if(a[i]*b[i]==0 && a[i]!=b[i]) cnt += max(a[i],b[i]);
    }
    cout << cnt;

}
