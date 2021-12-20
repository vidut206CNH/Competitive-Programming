#include<iostream>

using namespace std;
/*Viết chương trình nhập vào điểm trung bình của ba môn học Toán, Lý và Hóa của bạn.
 In ra màn hình trung bình cộng điểm của ba môn học trên.*/

int main() {
	int var1, var2, var3;
	cout << "Nhap diem 3 mon Toan,Ly va Hoa: ";
	cin >> var1 >> var2 >> var3;
	cout << "Diem trung binh 3 mon Toan,Ly va Hoa la: " << (var1+var2+var3)/3;
	return 0;
}