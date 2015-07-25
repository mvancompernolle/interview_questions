#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <string>

class HashTable{
public:
	HashTable(int length = 13);
	~HashTable();
	void insertItem(std::string item);
	bool removeItem(std::string key);
	bool hasItem(std::string key);
	void printTable() const;
	void printHistorgram() const;
	int getLength() const;
	int getNumberOfItems() const;

private:
	std::list<std::string>* array;
	int length;
	int hash(std::string key);
};

#endif