#include <iostream> 
#include<fstream>
#include<string>
using namespace std;

int main() {

    //output file stream data type
    ofstream myfile;
    //open creates the file if it does not exist
    myfile.open("csciAwesomeFile.txt");

    //output to file works just like 'cout' using insertion operator '<<'
    myfile << "Line one in file.\n";
    myfile << "Line two in file.\n";
    myfile << "Line three in file.\n";

    myfile.close();

    //input file stream data type
    ifstream myfile2;
    myfile2.open("csciAwesomeFile.txt");
    string stringVar;

    //input from file works just like 'cin' using extraction operator '>>'
    myfile2 >> stringVar;
    cout << stringVar << endl;

    // Use getline (from string library) in same way
    getline(myfile2, stringVar);
    cout << stringVar << endl;

    //To get all the lines cycle through to END OF FILE (eof)
    while (!myfile2.eof()) {
        getline(myfile2, stringVar);
        cout << stringVar << endl;
    }
    
    myfile2.close();

    return(0);
}