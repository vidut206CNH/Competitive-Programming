#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    string ps;
    cin >> ps;
    bool arr[4];
    string s0 = "0123456789";
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s3 = "!@#$%^&*()-+";
    vector<string> vec;
    vec.push_back(s0);
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    for (int i=0;i<n;++i) {
        if(vec[0].find(ps[i])<vec[0].size())  arr[0] = true;
        else if(vec[1].find(ps[i])<vec[1].size())  arr[1] = true;
        else if(vec[2].find(ps[i])<vec[2].size())  arr[2] = true;
        else arr[3] = true;
    }
    for (int i=0;i<4;++i) {
        if (arr[i] == false) {
            n += 1;
            cnt += 1;
        }
    }
    if (n<6) {
        cnt += (6-n);
    }
    cout << cnt;
}
