// Hashing Lab notes

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <list>
using namespace std;

// hash function (Keep it simple)
int hashFunction(int ID, int tableSize) {
	return(ID % tableSize);
}
void simplePrintTable(list<int>[], int); //pass array and size

int main(void) {
	srand(time(0));
	const int tableSize = 100;

	// A c-type ARRAY of integer lists -- Want the indexing here.
	list<int> hashTable[tableSize];

	// put something in the first bucket which is a list.
	hashTable[0].push_back(555);  

	//print the hash table
	simplePrintTable(hashTable, tableSize);

	cout << "\n*** Part II ***\n" << endl;

	// populate the hash table with lots of collisions
	for (int i = 0; i < 100; i++) {
		int value = rand();
		int key = hashFunction(value, tableSize);
		hashTable[key].push_back(value);
	}

	//print the hash table
	simplePrintTable(hashTable, tableSize);

	return(0);
}

//Implementations
void simplePrintTable(list<int> arg[], int size) {
	// Print the buckets...
	list<int>::iterator myItr;

	for (int i = 0; i < size; i++) {
		cout << "bucket " << i << " ==> ";
		myItr = arg[i].begin();

		while (myItr != arg[i].end()) {
			cout << *myItr << ", ";
			myItr++;
		}
		cout << endl;
	}
}