#include<bits/stdc++.h>

using namespace std;
bool a[200];

int main() {
    int n;
    int k=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;++i) {
        a[(int)(s[i])] = true;
    }
    for(int i =  'a';i<= 'z';++i) {
        if(a[i]) {
            int j =i+1;
            while(j<= 'z') {
                if(a[j]) {
                    string str = "";
                    for(int l=0;l<n;++l) {
                        if((s[l]==i) || (s[l]==j)) {
                            str += s[l];
                        }
                    }
                    int t = str.size();
                    for(int l=0;l<t;++l) {
                        if(str[l]== str[l+1]) break;
                        if(l == t-1) k = max(t,k);
                    }
                }
                ++j;
            }
        }
    }
    cout << k;

}
