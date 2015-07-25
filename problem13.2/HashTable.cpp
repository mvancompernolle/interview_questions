#include "HashTable.h"

#include <iostream>
#include <algorithm>

HashTable::HashTable(int length){
	array = new std::list<std::string>[length];
	this->length = length;
}

HashTable::~HashTable(){
	delete[] array;
}

void HashTable::insertItem(std::string key){
	array[hash(key)].push_back(key);
}

bool HashTable::removeItem(std::string key){
	array[hash(key)].remove(key);
}

bool HashTable::hasItem(std::string key){
	int pos = hash(key);
	return (std::find(array[pos].begin(), array[pos].end(), key) != array[pos].end());
}

void HashTable::printTable() const{
	std::cout << "\n\nHash Table:\n";
	for(int i=0; i < length; i++){
		std::cout << "Bucket " << i + 1 << ": ";
		for(std::list<std::string>::iterator it = array[i].begin(); it != array[i].end(); it++){
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void HashTable::printHistorgram() const{
	std::cout << "\n\nHash Table Contains ";
	std::cout << getNumberOfItems() << " Items total \n";

	for(int i=0; i < length; i++){
		std::cout << i + 1 << ":\t";
		for(int j=0; j < array[i].size(); j++){
			std::cout << " X";
		}
		std::cout << std::endl;
	}
}

int HashTable::getLength() const{
	return length;
}

int HashTable::getNumberOfItems() const{
	int numItems = 0;
	for(int i=0; i<length; i++){
		numItems += array[i].size();
	}
	return numItems;
}

int HashTable::hash(std::string key){
	int value = 0;
	for(int i=0; i < key.length(); i++)
		value += key[i];
	return (value * key.length()) % length;
}
