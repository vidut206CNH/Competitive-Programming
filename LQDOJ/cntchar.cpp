#include<bits/stdc++.h>

using namespace std;




int main() {
    int arr[256];
    int cnt =0;
    memset(arr,0,sizeof(arr));
    string s;
    cin >> s;

    for(int i=0;i<s.size();++i) {
        int a = s[i];
        arr[a] += 1;
    }
    for(int i=0;i<256;++i) {
        if(arr[i] == 1) cnt += 1;
    }
    cout <<cnt;
}
