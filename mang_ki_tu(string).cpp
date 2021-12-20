#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
	char foo[20];
	char foo1[30];
	memset(foo, 'a', sizeof(foo));
	foo[sizeof(foo) - 1] = '\0';
	cout << "Foo: " << foo << "\n";
	strcpy(foo1,foo);
	cout << "Foo1: " << foo1;
}