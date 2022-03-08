// Define our includes
#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "token.h"

// Scanner prototype
token scanner(
	ifstream& ifile, 
	int lineNum
);

// Prototype to lookup column on FSA table
int column_lookup(
	char nextChar
);

// Protoype to map token and keywords
token lookup(
	int value, 
	string searchString
);

// Define our CLookup structure
struct c_lookup {
	char value;
	int key;
};

// Define our TLookup structure
struct t_lookup {
	int key;
	TokenID token_enum;
};

#endif
