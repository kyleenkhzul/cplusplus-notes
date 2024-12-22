#include <iostream>
#include "strextra.h"

using namespace std; 

int main() {
    const char* str1 = "Hello";
    const char* str2 = "hello";
	
	const char* str3 = "Bye";
    const char* str4 = "Goodbye";
	
	const char* str5 = "Zinc";
    const char* str6 = "Thanks";
	
	if(strcmp_ncase(str1, str2) == 0) {
		cout << str1 << " and " << str2 << " are the same!\n";
	}
	else {
		cout << str1 << " and " << str2 << " are not the same!\n";
	}
	
	if(strcmp_ncase(str3, str4) == 0) {
		cout << str3 << " and " << str4 << " are the same!\n";
	}
	else {
		cout << str3 << " and " << str4 << " are not the same!\n";
	}
	
	if(strcmp_ncase(str5, str6) == 0) {
		cout << str5 << " and " << str6 << " are the same!\n";
	}
	else {
		cout << str5 << " and " << str6 << " are not the same!\n";
	}
	
    return 0;
}