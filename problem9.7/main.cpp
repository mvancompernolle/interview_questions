#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

struct person{
	int height, weight;
};

int largestNum(std::vector<person> people);
bool comparePerson(const person& p1, const person& p2);

int main(int argc, char* argv[]){

	std::srand(std::time(NULL));

	std::vector<person> people;

	person p;

	for(int i=0; i<10000; i++){
		p.height = (rand()%50) + 50;
		p.weight = (rand()%100) + 100;
		people.push_back(p);
	}

	std::sort(people.begin(), people.end(), &comparePerson);

	// for(int i=0; i<people.size(); i++){
	// 	std::cout << people[i].height << " " << people[i].weight << std::endl;
	// }

	std::cout << largestNum(people) << std::endl;

	return 0;
}

int largestNum(std::vector<person> people){
	int partialAnswers[people.size()];
	std::vector<person> towers[people.size()];

	for(int i=0; i<people.size(); i++){
		partialAnswers[i] = 1;
		towers[i].push_back(people[i]);
	}

	int bestAnswer = 1;
	int bestIndexToAdd = -1;

	// calculate best answer for each at bottom
	for(int i=1; i<people.size(); i++){
		bestIndexToAdd = -1;
		for(int j=i-1; j >= 0; j--){
			if(partialAnswers[j] + 1 > partialAnswers[i] && people[i].weight >= people[j].weight){
				partialAnswers[i] = partialAnswers[j] + 1;
				bestIndexToAdd = j;

				if(partialAnswers[i] > bestAnswer)
					bestAnswer = partialAnswers[i];
			}
		}

		if(bestIndexToAdd != -1){
			// append best subtower to this towers best answer
			towers[i].insert(towers[i].end(), towers[bestIndexToAdd].begin(), towers[bestIndexToAdd].end());
		}
	}

	// // print best answers
	// for(int i=0; i<people.size(); i++){
	// 	for(int index=0; index < towers[i].size(); index++){
	// 		std::cout << towers[i][index].height << " " << towers[i][index].weight << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }

	return bestAnswer;
}

bool comparePerson(const person& p1, const person& p2){
	if(p1.height <= p2.height){
		if(p1.height == p2.height){
			if(p1.weight <= p2.weight)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}