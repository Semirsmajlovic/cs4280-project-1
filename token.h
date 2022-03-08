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
	equalsTk, 
	greatTk, 
	great_eqTk, 
	lessTk, 
	less_eqTk, 
	double_equalsTk,
	colonTk, 
	colon_equalsTk, 
	plusTk, 
	minusTk, 
	asteriskTk,
	slashTk, 
	modulusTk, 
	periodTk, 
	open_parTk, 
	close_parTk,
	commaTk, 
	open_curlTk, 
	close_curlTk, 
	semicolonTk,
	open_bracketTk, 
	close_bracketTk
};

// Token structure
struct token {
	TokenID token_identifier;
	string token_name;
	int line_number;
};

#endif
