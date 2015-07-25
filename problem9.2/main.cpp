#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct oldLoc{
	std::string str, oldStr;
};

void sortAnagrams(std::string arr[], int num);
bool compareOldLoc(const oldLoc& s1, const oldLoc& s2);
bool compareAnagrams(const std::string& s1, const std::string& s2);

int main(int argc, char* argv[]){
	std::string strings[6];
	strings[0] = "hello";
	strings[1] = "meow";
	strings[2] = "lohle";
	strings[3] = "ingrst";
	strings[4] = "wome";
	strings[5] = "string";

	for(int i=0; i<6; i++){
		std::cout << strings[i] << std::endl;
	}
	std::cout << std::endl;

	//sortAnagrams(strings, 6);
	std::sort(std::begin(strings), std::end(strings), &compareAnagrams);

	for(int i=0; i<6; i++){
		std::cout << strings[i] << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

void sortAnagrams(std::string arr[], int num){
	// create a copy of the array of strings
	std::vector<oldLoc> copy(num);
	for(int i=0; i<num; i++){
		copy[i].str = copy[i].oldStr = arr[i];

		// sort the letters in each string
		std::sort(copy[i].str.begin(), copy[i].str.end());

		std::cout << copy[i].str << " " << copy[i].oldStr << std::endl;
	}
	std::cout << std::endl;

	// sort the array of sorted strings
	std::sort(copy.begin(), copy.end(), &compareOldLoc);

	// swap strings in original array to their new positions
	for(int i=0; i<num; i++){
		arr[i] = copy[i].oldStr;
	}
}

bool compareOldLoc(const oldLoc& s1, const oldLoc& s2){
	if(s1.str.compare(s2.str) < 0)
		return true;
	else
		return false;
}

bool compareAnagrams(const std::string& s1, const std::string& s2){
	std::string tmp1 = s1;
	std::string tmp2 = s2;
	std::sort(tmp1.begin(), tmp1.end());
	std::sort(tmp2.begin(), tmp2.end());

	if(tmp1.compare(tmp2) < 0)
		return true;
	else
		return false;
}