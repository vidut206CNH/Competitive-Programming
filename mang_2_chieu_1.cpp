#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int arr[50][50];
	int level;
	cout << "Enter level of square matrix: ";
	cin >> level;
	--level;
	for (int row=0;row<= level;++row) {
		for (int col=0;col <= level;++col) {
			cout << "\nEnter " << "[" << row+1 <<"]" <<"[" <<col+1 << "] : ";
			cin >> arr[row][col];
		}
	}
	cout << "======================\n";
	for(int i=0;i<=level;i++) {
		cout << "\t";
		for (int j=0;j<=level;j++) {
			if (arr[i][j] <=9) {
			cout << arr[i][j] << "  ";	
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
	int rev_row;
	cout << "\n=======================\n";
	cout << "Enter the row you want to remove: ";
	cin >> rev_row;
	--rev_row;
	for (int l=rev_row;l<=level-1;l++) {
		for (int k=0;k<=level;k++) {
			arr[l][k] = arr[l+1][k];
		}
	}
	for(int i=0;i<=level-1;i++) {
		cout << "\t";
		for (int j=0;j<=level;j++) {
			cout << arr[i][j] << "  ";
		}
		cout << "\n";
	}
	return 0;
}