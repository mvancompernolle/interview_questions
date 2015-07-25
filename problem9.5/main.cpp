#include <iostream>
#include <string>

int searchString(std::string arr[], int min, int max, std::string val, std::string prev);

int main(int argc, char* argv[]){

	std::string strings[13];
	strings[0] = "at";
	strings[1] = "";
	strings[2] = "";
	strings[3] = "";
	strings[4] = "ball";
	strings[5] = "";
	strings[6] = "";
	strings[7] = "car";
	strings[8] = "";
	strings[9] = "";
	strings[10] = "dad";
	strings[11] = "";
	strings[12] = "";

	int mid = 12 / 2;
	int index = -1;
	if(strings[mid].compare("ball") == 0)
		index = mid;
	else
		index = searchString(strings, 0, 12, "car", strings[mid]);

	std::cout << "Index: " << index << std::endl;
	

	return 0;
}

int searchString(std::string arr[], int min, int max, std::string val, std::string prev){
	if(min > max)
		return -1;

	int mid = (min + max)/2;

	std::cout << "mid: " << mid << std::endl;

	int index = mid;
	if(arr[mid].compare("") == 0){
		// scan for a nearby string
		// scan right
		index = mid+1;
		bool found = false;
		while(index <= max){
			if(arr[index].compare("") != 0 && arr[index].compare(prev) != 0){
				found = true;
				break;
			}
			index++;
		}

		// if no string found to right, scan left
		if(!found){
			index = mid - 1;
			while(index >= min){
				if(arr[index].compare("") != 0 && arr[index].compare(prev) != 0){
					found = true;
					break;
				}
				index--;
			}
		}

		// if no new string found return -1
		if(!found)
			return -1;
	}

	if(arr[index].compare(val) == 0)
		return index;
	else if(arr[index].compare(val) > 0)
		return searchString(arr, min, index-1, val, arr[index]);
	else
		return searchString(arr, index+1, max, val, arr[index]);
}