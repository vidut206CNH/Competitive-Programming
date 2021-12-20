#include <iostream> 
#include <iomanip>
using namespace std; 
  
int main() {
	int i,j,ans;
	cout << "Bang nhan: \n";
	for (i=1;i<=10;i++) {
		for (j=1;j<=10;j++) {
			ans = i*j;
			cout << setw(5) << ans;
		}
		cout << "\n";
	}
	return 0;
}