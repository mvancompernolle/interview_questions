#include <iostream>

#include "SmartPointer.h"

int main(int argc, char* argv[]){

	SmartPointer<int> s_ptr(new int[1000]);
	char tmp;
	std::cin >> tmp;
	SmartPointer<int> s_ptr2(new int[1000]);	
	s_ptr = s_ptr2;
	std::cin >> tmp;

	return 0;
}