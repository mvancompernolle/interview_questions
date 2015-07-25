#include <iostream>

#include "HashTable.h"

int main(int argc, char* argv[]){

	HashTable table;
	table.insertItem("hello");
	table.insertItem("me");
	table.insertItem("you");
	table.insertItem("them");
	table.insertItem("they");
	table.insertItem("pray");
	table.insertItem("vancompernolle");
	table.insertItem("jello");
	table.insertItem("sucka");
	table.insertItem("hehe");
	table.insertItem("lizzard");
	table.insertItem("bj");
	table.printTable();
	table.printHistorgram();
	table.removeItem("me");
	table.removeItem("you");
	table.removeItem("lala");
	table.printTable();
	table.printHistorgram();

	return 0;
}