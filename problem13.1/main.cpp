#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int argc, char* argv[]){

	int numLines = std::atoi(argv[1]);
	std::string lines[numLines];
	int pos = 0;

	std::ifstream fin("input.txt");
	if(fin.good()){
		while(fin.good()){
			std::getline(fin, lines[pos % numLines]);
			pos++;
		}
	}

	int start, count;
	if(pos < numLines){
		start = 0;
		count = pos;
	}
	else{
		start = pos % numLines;
		count = numLines;
	}

	for(int i=0; i<count; i++){
		std::cout << lines[(start + i) % numLines] << std::endl;
	}

	return 0;
}