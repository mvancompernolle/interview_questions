#include <iostream>
#include <algorithm>

void findElement(const std::string matrix[], int rows, char element, int& r, int& c);
int binarySearch(const std::string str, int min, int max, char element);

int main(int argc, char* argv[]){

	char target = argv[1][0];

	std::string arr[5];
	arr[0] = "hetlo";
	arr[1] = "liuzy";
	arr[2] = "apqle";
	arr[3] = "zebrd";
	arr[4] = "grxpm";

	// sort each string by characters
	for(int i=0; i<5; i++)
		std::sort(arr[i].begin(), arr[i].end());

	// sort between strings
	std::sort(std::begin(arr), std::end(arr));

	for(int i=0; i<5; i++)
		std::cout << arr[i] << std::endl;

	// search for element
	int row, column;
	findElement(arr, 5, target, row, column);
	if(row == -1)
		std::cout << "Element was not found" << std::endl;
	else
		std::cout << "Row: " << row << " Column: " << column << std::endl;

	return 0;
}

void findElement(const std::string matrix[], int rows, char element, int& r, int& c){
	// search through each row to find element
	for(int i=0; i<rows; i++){
		if(matrix[i][0] > element){
			r = -1;
			c = -1;
			return;
		}
		else{
			c = binarySearch(matrix[i], 0, matrix[i].size()-1, element);
			if(c != -1){
				r = i;
				return;
			}
		}
	}

	r = c = -1;
}

int binarySearch(const std::string str, int min, int max, char element){
	if(min > max)
		return -1;

	int mid = (min + max)/2;
	std::cout << "val at mid: " << str[mid] << std::endl;

	if(str[mid] == element)
		return mid;
	else if(element > str[mid])
		return binarySearch(str, mid+1, max, element);
	else
		return binarySearch(str, min, mid-1, element);
}