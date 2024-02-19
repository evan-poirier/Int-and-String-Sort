#include <iostream>
#include <string> 
#include <fstream> 
#include <sstream> 
#include <cctype> 
#include <iomanip> 
#include <climits>

using namespace std;

void CheckArgumentCount(int count); // checks argc in main to ensure program is being used properly

ifstream OpenFile(string fileName); // attempts to open a file

int main (int argc, char * argv[]) {

    // check for valid # of command line arguments
    CheckArgumentCount(argc);


    // determine what type of data will be scanned from files and store in intFile bool
    bool intFile = true;

    if (argv[1][0] == 's') {
        intFile = false;
    } else if (argv[1][0] != 'i') {
        cout << "Second command must be \"i\", for sorting integers, or \"s\", for sorting strings" << endl;
        return 1;
    }


    // attempt to open both files
    ifstream file1 = OpenFile(argv[2]);
    ifstream file2 = OpenFile(argv[3]);


    // check to see if files opened successfully
    if (!file1.is_open() || !file2.is_open()) {
        cout << "One or more of the files did not open successfully." << endl;
        return 1;
    }


    // create arrays
    int int1[20000] = {123456789}; // will later be used to check if an index has been read from file or not
    int int2[20000] = {123456789};

    string string1[20000] = {"uninitialized"};
    string string2[20000] = {"uninitialized"};

    // read data
    if (intFile) {
        file1 >> int1[0];
        //
        cout << "int1[0] = " << int1[0] << endl;

        int i = 1;

        while (!file1.eof()) {
            file1 >> int1[i];
            //
            cout << "int1[" << i << "] = " << int1[i] << endl;

            i ++;
        }

        file2 >> int2[0];
        int j = 1;
        while (1) {
            file2 >> int2[j];
            if (file1.eof()) {
                break;
            }
            cout << int2[j] << endl;
            j ++;
        }
    } else {
        file1 >> string1[0];
        int i = 1;
        while (!file1.eof()) {
            file1 >> string1[i];
            i ++;
        }

        file2 >> string2[0];
        int j = 1;
        while (!file2.eof()) {
            file2 >> string2[j];
            j ++;
        }
    }

    /* test
    int i = 0;
    while (1) {
        if (int1[i] == 123456789) {
            cout << endl << "Reached end of array." << endl;
            break;
        } else {
            cout << "Index " << i << ": " << int1[i] << endl;
        }
        i ++;
    }
    */

  
    return 0;
}

void CheckArgumentCount(int count) {
    if (count != 4) {
        cout << "Usage: ./a.out sort_type file1 file2" << endl;
    }
}

ifstream OpenFile(string fileName) {
    ifstream returnFile;
    returnFile.open(fileName);

    return returnFile;
}