// Define our includes
#include <iostream>
#include <fstream>
#include "testScanner.h"

using namespace std;

// Main
int main(int argc, char *argv[]) 
{
	// Define variables
	string file_name;
	ifstream invoked_file;

	// Throw error if more than two arguments are passed
	if (argc > 2) {
		cout << "Error: Please use one of the following formats: ./scanner file_name or ./scanner < file_name.ext\n";
		return 1;
		
	// Handle our single ./scanner temp append call
	} else if (argc == 2) {
		file_name = argv[1];
		file_name.append(".sp2022");

	// Handle our single argument and execute
	} else if (argc == 1) {

		// Invoke try/catch conditional
		try {
			// Set our variables
			string client_input;
			ofstream temporary_file;

			// Define our temporary file
			file_name = "temp.sp2022";

			// Open our temporary file
			temporary_file.open(
				file_name.c_str()
			);

			// Create our loop
			while (getline(cin, client_input)) {
				temporary_file << client_input << "\n";
			}

			// Terminate loop and close temporary file
			temporary_file.close();

		// Handle our catch on non-existant file
		} catch (const ifstream::failure &e) {
			cout << "Error: The file could not be found, please make sure that the correct file name is provided.\n";
			return 1;
		}
	}

	// Call our testScanner file
	invoked_file.open(
		file_name.c_str()
	);
	testScanner(invoked_file);

	// Close input file
	cout << "\nOur file execution will now be terminated.\n";
	invoked_file.close();

	return 0;
}
