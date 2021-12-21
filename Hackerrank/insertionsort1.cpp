#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n) {
    for (int i=0;i<n;++i) cout << arr[i] << ' ';
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;++i) cin >> arr[i];
    int j=n-2,temp = arr[n-1];
    while(j>=0) {
        if(arr[j]>temp) {
            arr[j+1] = arr[j];
            printArray(arr,n);
            cout << '\n';
        }
        else {
            arr[j+1] = temp;
            printArray(arr,n);
            cout << '\n';
            return 0;
        }
        j--;
    }
    arr[0] = temp;
    printArray(arr,n);

}
