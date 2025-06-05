#include <stdexcept> // for standard exceptions
#include <iostream> // for cin, cout, cerr
#include <string> 
#include <cctype> // for isdigit
#include <algorithm> // for all_of
using namespace std;

int	main(void)
{
	string	S;
	bool	check;
	
	getline (cin, S);
	try // block where exceptions might occur
	{
		check = all_of(S.begin(), S.end(), [](char c) // checking every member of the S
		{ // It also might be a vector<int> as an example
		  // range might start/end with a pointer to an array or an array + i
		  // any_of, none_of, count_if, find_if, transform, remove_if
		  // Inside [] we can put &data to handle it in {} block
			return isdigit(c) ? true : throw invalid_argument("Bad String");
		});//throw creates an exception object
		cout << S << endl;
	}
	catch (const invalid_argument &error) // It catches all the exceptions
	{// so if there are a few of them, they should be handled inside catch block
		cout << error.what() << endl;
	}
	return 0;
}
