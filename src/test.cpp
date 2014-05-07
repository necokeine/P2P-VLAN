#include "include/uInt160.h"
#include <iostream>
using namespace std;


int main() {
	uInt160 a(100000, 10, 10, 10, 0), b(20, 20, 20, 20, 20);
	cout<<a<<endl;
	cout<<(a ^ b)<<endl;
}
