// Define our includes
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

using namespace std;

// Define our enum
enum TokenID {
	// EOF and error tokens
	end_of_token, 
	token_error,

	// Identifiers and integers tokens
	token_id, 
	token_number,

	// Keyword tokens
	token_begin, 
	token_end, 
	loop_token, 
	whole_token, 
	void_token, 
	token_exit,
	token_getter, 
	token_outter, 
	main_token, 
	if_token, 
	then_token, 
	assign_token,
	data_token, 
	proc_token,

	// Operator and delimiter tokens
	equals_token, 
	great_token, 
	great_eq_token, 
	less_token, 
	less_eq_token, 
	double_equals_token,
	colon_token, 
	colon_equals_token, 
	plus_token, 
	minus_token, 
	asterisk_token,
	slash_token, 
	modulus_token, 
	period_token, 
	open_par_token, 
	close_par_token,
	comma_token, 
	open_curl_token, 
	close_curl_token, 
	semicolon_token,
	open_bracket_token, 
	close_bracket_token
};

// Token structure
struct token {
	TokenID token_identifier;
	string token_name;
	int line_number;
};

#endif
