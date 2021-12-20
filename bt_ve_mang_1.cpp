/* Nhập từ bàn phím mảng số nguyên gồm n phần tử.

Tính trung bình cộng các số lẻ ở vị trí chẵn
Tìm số lớn nhất trong mảng vừa nhập
Tìm vị trí các số nhỏ nhất trong mảng
Đếm các số chính phương có trong mảng
Hiện thị các số nguyên tố có trong mảng lên màn hình
Thay thế các phần tử âm có trong mảng bằng giá trị 0
Xóa các phần tử âm có trong mảng
Sắp xếp mảng đã nhập theo thứ tự tăng dần */

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

const int MAX = 5;

void NhapMang(int a[], int n) {
	for (int i=0;i<=n;++i) {
		printf("\n Nhap a[%d] = ", i );
		scanf("%d", &a[i]);
	}
}

int main() {
	int a[MAX];
	int n;
	printf("Nhap n: \n"); 
	scanf("%d", &n);
	NhapMang(a, n);

	return 0;
}
