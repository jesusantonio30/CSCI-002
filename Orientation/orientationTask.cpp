// Playing around with random numbers
// CSCI 002 

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main(){

	// Time given as the number of seconds since Jan. 1, 1970
	cout << time(0) << endl;

	// Seed the random number generator with the time,
	// which will be different each time you execute the program
	srand( time(0) );

	// Now the randomness can be seen each time you run
	cout << "Random Number ( 1 - 10): " << 1 + rand()%10 << endl;
	cout << "Random fractions: " << 1.0 * rand() / RAND_MAX << endl;

	// Now say we want a random character from a - z.
	// First you need to know that characters have numerical equivalents
	// Google "ASCII char table"

	// Cast the numeric code for a to a char like this
	cout << "code 97: " << char(97) << endl;

	for (int i = 98; i < 122; ++i) {
		cout << "code " << i << ": " << char(i) << endl;
	}


	cout << "code 122: " << char(122) << endl;

	// so we need a random number from 97 to 122 to generate
	// random characters (lower case, note 97 + 25 = 122).
	cout << "Random Character ( a - z ): " << char( 97 + rand()%26 ) << endl;

	string myName = "Jesus Morales";

	for (int i = 0; i < myName.size(); ++i) {
		cout << myName[i] << " = " << int(myName[i]) << endl;
	}

	return (0);

}
