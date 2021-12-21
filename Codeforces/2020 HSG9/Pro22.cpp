#include<bits/stdc++.h>

using namespace std;


void Print(string s) {
    string::iterator it1;
    string date="";
    int i=0;
    while(true) {
        if(s[i]!='#')cout << s[i];
        else {
            cout << '@';
            break;
        }
        ++i;
    }
    ++i;
    while(s[i] != '#') {
        date += s[i];
        ++i;
    }
    while(i<s.size()-3) {
        if(s[i]!='#') cout << s[i];
        i++;
    }
    cout << '@' << date << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    bool chk=0;
    cin >> n;
    vector<string> str;
    for(int i=0;i<n;++i) {
        string s;
        if(i==0) getline(cin,s);
        getline(cin,s);
        int t=s.size();
        if(s.substr(t-3,2) == "Ti") {
            chk = 1;
            str.push_back(s);
        }
    }
    if(chk) {
        cout << "Mon thi chuyen: Tin hoc" << '\n' << "Thong tin thi sinh" << '\n';
        for(auto x :str) {
            Print(x);
        }
        cout << "Danh sach gom co: " << str.size() << " thi sinh";
        return 0;
    }
    else cout << '#';

}
