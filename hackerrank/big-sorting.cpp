#include<bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    if (a.size()==b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> vec;
    for (int i=0;i<n;++i) {
        cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end(),comp);
    for (int i=0;i<vec.size();++i) {
        cout << vec[i] << '\n';
    }
}
