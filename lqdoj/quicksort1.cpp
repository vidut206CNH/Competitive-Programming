#include<bits/stdc++.h>

using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void solve (int arr[],int n) {
    int pivot = arr[0];
    int i=n,j=n-1;
    while(j>=0) {
        if(arr[j]>=pivot) {
            --i;
            swap(arr[j],arr[i]);
        }

        j--;
    }

}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i) cin >> arr[i];
    solve(arr,n);
    for(int i=0;i<n;++i) cout << arr[i] << ' ';

}
