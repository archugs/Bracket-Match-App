#include "stack.h"
#include <fstream>
using namespace std;

int main()
{
	Stack openings;
	char symbol;
	
	char filename[30];
	cout << "Enter the filename to be scanned for bracket checking" << endl;
	cin >> filename;
	ifstream input_file (filename);

	bool is_matched = true;
	
	if ( input_file.is_open() )
	{
		while ( ! input_file.eof() )
		{
			symbol = input_file.get();

			/* checking for C++ comments and ignoring them */
			if (symbol == '/')
			{
				char symbol2 = input_file.get();
				if (symbol2 == '/')
				{
					while(input_file.get() != '\n')
					{
						continue;
					}
				}
				
				else if (symbol2 == '*')
				{
					while (! ((input_file.get() == '*') && (input_file.get() == '/')) )
					{
						continue;
					}
				
					continue;
				}
				
				else
				{
					continue;
				}
			}


			/* checking for character strings and ignore them */
			if (symbol == '"')
			{
				while (input_file.get() != '"')
				{
					continue;
				}
				continue;
			}

			if (symbol == '{' || symbol == '(' || symbol == '[')
			{
				cout << symbol << endl;
				openings.push(symbol);
			}
			
			if (symbol == '}' || symbol == ')' || symbol == ']')
			{
				cout << symbol << endl;

				if(openings.empty())
				{
					cout << "Unmatched closing bracket" << symbol << "detected" << endl;
				}

				else
				{
					char match;
					openings.top(match);
					openings.pop();
					is_matched = (symbol == '}' && match == '{') || (symbol == ')' && match == '(') || (symbol == ']' && match == '[');

					if (! is_matched)
					{
						cout << "Bad match" << match << symbol << endl;
					}
				}
			}
		}

		if (! openings.empty())
		{
				cout << "Unmatched opening bracket(s) detected" << endl;	
		}
			
		
		input_file.close();	
	}

	else
	{
		cout << "Unable to open file" << endl;
	}
}


