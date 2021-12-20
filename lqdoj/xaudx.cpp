#include<bits/stdc++.h>

using namespace std;

int arr[200];
int main() {
    string s;
    int cnt=0;
    memset(arr,0,sizeof(arr));
    cin >> s;
    for(int i=0;i<s.size();++i) arr[s[i]] += 1;
    for(int i='a';i<='z';++i) {
        if(arr[i]%2 != 0) cnt += 1;
    }
    if(cnt == 0) cout << cnt;
    else cout << cnt-1;
}
