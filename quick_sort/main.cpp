#include <iostream>
#include <vector>

void quickSort(int arr[], int left, int right);

int main(int argc, char* argv[]){

	int arr[] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
	quickSort(arr, 0, 8);

	for(int i=0; i<9; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right)/2];

	while(i <= j){
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;

		if(i <= j){
			if(i != j){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;	
			}

			i++;
			j--;
		}
	}

	if(left < j)
		quickSort(arr, left, j);
	if(i < right)
		quickSort(arr, i, right);
}
