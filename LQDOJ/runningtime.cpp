#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;++i) {
        cin >> arr[i];
        int j=i-1;
        int temp = arr[i];
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = temp;
        sum += (i-j-1);
    }
    cout << sum;
}
