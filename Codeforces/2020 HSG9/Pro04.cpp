#include<bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

string sumstring(string &s1, string &s2) {
    if(s2.size()>s1.size()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    int n1=s1.size(),n2=s2.size();
    int carry = 0,sum;
    string str = "";
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<n2;++i) {
        sum =((s1[i]-'0') + (s2[i] -'0') + carry);
        str += (sum%10+'0');
        carry = sum/10;

    }
    for(int i=n2;i<n1;++i) {
        sum = ((s1[i] - '0') + carry);
        str += (sum%10+'0');
        carry = sum/10;
    }
    if(carry) str += '1';
    reverse(str.begin(),str.end());
    while(str.size()!=0) {
        if(str[0] == '0') str.erase(0,1);
        else break;
    }
    return str;
}


int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string str1="",str2="",s;
    string s1,s2;
    int n;
    cin >> n;
    getline(cin, s);
    getline(cin, s1);
    getline(cin, s2);
    stringstream ss1(s1),ss2(s2);
    while(ss1 >> s) str1 += s;
    while(ss2 >> s) str2 += s;
    cout << sumstring(str1,str2);
}
