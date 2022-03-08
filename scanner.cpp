// Define our includes
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "scanner.h"

using namespace std;

// Define our table
int table[26][24] = 
{
	{   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,   -1},
	{1000,    1,    1, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000},
	{1001, 1001,    2, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001},
	{1002, 1002, 1002,   22,   23,   24, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
	{1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005},
	{   9,    9,    9, 1002, 1004, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
	{1000,    1,    1, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000},
	{1008, 1008, 1008,   25, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008},
	{1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010},
	{1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011},
	{1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012},
	{1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013},
	{1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014},
	{1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015},
	{1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016},
	{1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017},
	{1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018},
	{1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019},
	{1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020},
	{1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021},
	{1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022},
	{1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023},
	{1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007},
	{1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006},
	{1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004},
	{1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009},
};

// Scanner
token scanner(ifstream& ifile, int line_num)
{
	// Define our variables
	token return_token;
	static int line_number = line_num;
	char current_character;
	char next_character;
	int column;
	int current = 0;
	int next = 0;
	string token_string;

	// Handle our loop
	while (current < 1000 && current >= 0) 
	{
		ifile.get(
			current_character
		);

		// Check if we are currently at the end of the file
		if (ifile.eof()) {
			return_token.token_identifier = end_of_token;
			return_token.line_number = line_number;
			return_token.token_name = "EOF";

			return return_token;
		}

		// Bypass all $$ comments
		if (current_character == '$') {
			
			// Define line
			int line = line_number;
			
			// 
			ifile.get(
				current_character
			);
			ifile.get(
				current_character
			);
			ifile.get(
				next_character
			);

			// Loop through our characters
			while (current_character != '$' && next_character != '$') {
				
				// Define our current_character variable
				current_character = next_character;
				ifile.get(
					next_character
				);

				// Check if comment started but never closed
				if (ifile.eof()) {
					cout << "Error: The comment was started at line " << line << " but was never terminated.\n";
					return_token.token_identifier = token_error;
					return_token.line_number = line;
					return_token.token_name = "Error";

					return return_token;
				}

				// Handle our line skips
				if (next_character == '\n') {
					line_number++;
				}
			}

			ifile.get(
				current_character
			);
			ifile.get(
				current_character
			);
		}


		// Set our column lookup
		column = column_lookup(
			current_character
		);
		next = table[current][column];

		// Validate our character and check for invalid inputs
		if (column == -2) {
			cout << "Error: We have an error on line " << line_number << " with the following invalid character: " << current_character << "\n";
			return_token.token_identifier = token_error;
			return_token.line_number = line_number;
			return_token.token_name = current_character;

			return return_token;
		}

		// Define our if statement to handle next iterations
		if (next >= 1000 || next == -1) {

			// Check to see if we have hit our end of file with additional conditionals
			if (next == -1) {
				return_token.token_identifier = end_of_token;
				return_token.line_number = line_number;
				return_token.token_name = "EOF";

				return return_token;
			} else if (next == 1004 || next == 1006 || next == 1007 || next == 1009) {
				return_token = lookup(next, token_string);
				return_token.line_number = line_number;
				ifile.unget();

				return return_token;
			}
			else if (next == 1004 || next == 1006) {
				return_token = lookup(
					next, 
					token_string
				);
				return_token.line_number = line_number;
				ifile.unget();
				ifile.unget();

				return return_token;
			} else if(next >= 1000) {
				return_token = lookup(
					next, 
					token_string
				);
				return_token.line_number = line_number;
				ifile.unget();

				return return_token;
			}
		} else {
			char value = current_character;

			if (!isspace(value)) {
				token_string += value;
			}

			// Check our character count limit
			if (token_string.length() > 8) {
				cout << "Error: We have an error on line " << line_number << "\n";
				cout << "Error Description: The identifier " << token_string << " has exceeded 8 characters and/or digits.\n";
				return_token.token_identifier = token_error;
				return_token.line_number = line_number;
				return_token.token_name = "Error";

				return return_token;
			}

			// Handle our character break
			if (current_character == '\n') {
				line_number++;
			}

			current = next;
		}
	}

	// Return message if the scanner fails
	return_token.token_identifier = token_error;
	return_token.line_number = line_number;
	return_token.token_name = "Error: Our scanner has been terminated due to an error.\n";

	return return_token;
}

// Define our list of characters
c_lookup char_lookup[] = {
	{'=', 3}, 
	{'<', 4}, 
	{'>', 5}, 
	{'_', 6}, 
	{':', 7}, 
	{'+', 8},
	{'-', 9}, 
	{'*', 10}, 
	{'/', 11}, 
	{'%', 12}, 
	{'.', 13},
	{'(', 14},
	{')', 15},
	{',', 16},
	{'{', 17},
	{'}', 18},
	{';', 19},
	{'[', 20},
	{']', 21}
};

// Look for our column on our table
int column_lookup(char next_character) {
	if (isalpha(next_character)) {
		return 1;
	}
	else if (isdigit(next_character)) {
		return 2;
	}
	else if (isspace(next_character)) {
		return 0;
	}
	else if (next_character == EOF) {
		return 22;
	}
	else if (next_character != EOF || !isalpha(next_character) || !isdigit(next_character) || !isspace(next_character)) {
		for (int i = 0 ; i < (sizeof(char_lookup)/sizeof(char_lookup[0])) ; i++) {
			if (char_lookup[i].value == next_character) {
				return char_lookup[i].key;
			}
		}
	}

	return -2;
}

// Define our list of tokens
t_lookup token_lookup[] = 
{
	{-1, end_of_token},  
	{-2, token_error}, 
	{1000, token_id}, 
	{1001, token_number}, 
	{1002, equalsTk}, 
	{1003, greatTk}, 
	{1004, great_eqTk},
	{1005, lessTk}, 
	{1006, less_eqTk}, 
	{1007, double_equalsTk}, 
	{1008, colonTk}, 
	{1009, colon_equalsTk},
	{1010, plusTk}, 
	{1011, minusTk}, 
	{1012, asteriskTk}, 
	{1013, slashTk}, 
	{1014, modulusTk}, 
	{1015, periodTk},
	{1016, open_parTk}, 
	{1017, close_parTk}, 
	{1018, commaTk}, 
	{1019, open_curlTk}, 
	{1020, close_curlTk},
	{1021, semicolonTk}, 
	{1022, open_bracketTk}, 
	{1023, close_bracketTk}
};

// Define our list of keywords
token keyword_lookup[] = 
{
	{token_begin, "begin", 0}, 
	{token_end, "end", 0}, 
	{loop_token, "loop", 0}, 
	{whole_token, "whole", 0},
	{void_token, "void", 0}, 
	{token_exit, "exit", 0}, 
	{token_getter, "getter", 0}, 
	{token_outter, "outter", 0},
	{main_token, "main", 0}, 
	{if_token, "if", 0}, 
	{then_token, "then", 0}, 
	{assign_token, "assign", 0}, 
	{data_token, "data", 0}, 
	{proc_token, "proc", 0}
};

// Define our lookup token
token lookup(int value, string searchString) {
	token return_token;
	for (int i = 0 ; i < (sizeof(token_lookup) / sizeof(token_lookup[0])); i++) {
		if (token_lookup[i].key == value) {
			return_token.token_identifier = token_lookup[i].token_enum;
			return_token.token_name = searchString;
			return_token.line_number = 999;
		}
	}
	if (value == 1000) {
		for (int j = 0 ; j < (sizeof(keyword_lookup) / sizeof(keyword_lookup[0])) ; j++) {
			if (keyword_lookup[j].token_name == searchString) {
					return_token.token_identifier = keyword_lookup[j].token_identifier;
					return_token.token_name = keyword_lookup[j].token_name;
					return_token.line_number = 999;
			}
		}
	}

	return return_token;
}
