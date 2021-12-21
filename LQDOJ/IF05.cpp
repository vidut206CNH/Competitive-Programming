#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (b>a) {
        swap(a,b);
    }
    if (c>a) {
        swap(a,c);
    }
    if (c>b) {
        swap(b,c);
    }
    cout << a << " " << b << " " << c;

    return 0;
}
