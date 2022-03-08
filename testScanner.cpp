// Define our includes
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "testScanner.h"
#include "scanner.h"

using namespace std;

// Define our token names
string token_names[] = {
	"End of File",
	"Error",
	"Identifier",
	"Integer",
	"Begin Keyword",
	"End Keyword",
	"Loop Keyword",
	"Whole Keyword",
	"Void Keyword",
	"Exit Keyword",
	"Getter Keyword",
	"Outter Keyword",
	"Main Keyword",
	"If Keyword",
	"Then Keyword",
	"Assign Keyword",
	"Data Keyword",
	"Proc Keyword",
	"Equals Sign",
	"Greater Sign",
	"Greater Equal",
	"Less Sign",
	"Less Equal",
	"Double Equal",
	"Colon",
	"Colon Equal",
	"Plus Sign",
	"Minus Sign",
	"Asterisk",
	"Slash",
	"Modulus",
	"Period",
	"Open Parenthesis",
	"Close Parenthesis",
	"Comma",
	"Open Curly",
	"Close Curly",
	"Semicolon",
	"Open Bracket",
	"Close Bracket"
};

// Scanner's Driver
void testScanner(ifstream& ifile)
{
	// Define our variables
	token token;
	int line_number = 1;

	// Set our line break
	cout << "\n";

	// Set our while loop
	while (ifile) {

		// Define our token variable
		token = scanner(ifile, line_number);

		// Check for token identifiers w/ token_name
		if (token_names[token.token_identifier] == "Identifier" && isalpha(token.token_name[0])) {
			if (token.token_name[0] == toupper(token.token_name[0])) {
				cout << "Error: We have invalid characters " << token.token_name << " on line " << token.line_number << "\n";
				cout << "Error Description: We can't begin identifiers with a capital letter.\n";

				return;
			}
		}
		
		// Set our error turn handler or output our execution
		if (token_names[token.token_identifier] == "Error") {
			return;
		} else {
			cout << "[Line: " << token.line_number << "]\t[Token: " << token_names[token.token_identifier] << "]\t[Case: " << token.token_name << "]\n";
		}
	}

	return;
}
