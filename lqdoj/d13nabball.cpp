#include<bits/stdc++.h>

using namespace std;

void sorta(int arr[3]) {
    for (int i=0;i<2;++i) {
        for(int j=i+1;j<3;++j) {
            if (arr[j]<arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
 int arr[3];
 for (int i=0;i<3;++i) {
    cin >> arr[i];
 }
 sorta(arr);
 cout << arr[1];
}
