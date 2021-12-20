#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "\n Nhap so sinh vien: ";
	cin >> n;
	cout << "================";
	double mark[n],mark_max,mark_max_i;
	for (int i=0;i<=n-1;++i) {
		cout << "\nNhap diem sv "<<i+1<<" : ";
		cin >> mark[i];
	}
	mark_max = mark[0];
	mark_max = 0;
	for (int j=1;j<=n-1;j++) {
		if (mark_max < mark[j]) {
			mark_max = mark[j];
			mark_max_i = j+1;
		}
	}
	cout << "================";
	cout << "\n So diem cao nhat la:" << mark_max << " thuoc ve sinh vien thu " << mark_max_i;
	return 0;
}
