#include <iostream>

int findLowest(int arr[], int min, int max);
int findLowestHelper(int arr[], int min, int max, int start, int last);
int binarySearch(int arr[], int min, int max, int val);

int main(int argc, char* argv[]){
	int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

	int lowIndex = findLowest(arr, 0, 11);
	std::cout << "index: " << lowIndex << " val: " << arr[lowIndex] << std::endl;

	int index = binarySearch(arr, lowIndex, 13, 5);
	if(index == -1)
		index = binarySearch(arr, 0, lowIndex-1, 5);

	std::cout << "Value found at: " << index << std::endl;

	return 0;
}

int findLowest(int arr[], int min, int max){
	if(max == 0){
		return 0;
	}

	int start = (min + max)/2;
	int prev;

	if(start != 0)
		prev = start-1;
	else
		prev = max;

	if(arr[start] < arr[prev])
		return start;
	else{
		return findLowestHelper(arr, start+1, max, start, arr[start]);
	}
}

int findLowestHelper(int arr[], int min, int max, int start, int last){
	int mid = (min + max)/2;
	std::cout << "val: " << arr[mid] << " mid: " << mid << " min: " << min << " max: " << max << std::endl;

	int prev;
	if(mid != 0)
		prev = mid-1;
	else
		prev = max;

	if(arr[mid] < arr[prev]){
		return mid;
	}
	// continue right if value at mid greater than last
	else if(arr[mid] >= last){
		if(mid == max){
			return findLowestHelper(arr, 0, start-1, start, arr[mid]);
		}
		else{
			return findLowestHelper(arr, mid+1, max, start, arr[mid]);
		}
	}
	else{
		findLowestHelper(arr, min, mid-1, start, arr[mid]);
	}
}

int binarySearch(int arr[], int min, int max, int val){
	if(max < min)
		return -1;

	int mid = (min + max)/2;

	if(arr[mid] == val)
		return mid;
	else if(arr[mid] > val)
		return binarySearch(arr, min, mid-1, val);
	else
		return binarySearch(arr, mid+1, max, val);
}