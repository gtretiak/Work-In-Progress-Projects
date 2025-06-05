#include <iostream>
#include <string>
using namespace std;

int	ft_check_str(const string &s)
{
	if (s[0] != s[3])
	{
		if (s[1] == s[3] || s[0] == s[2])
			return (0);
		else
			return (1);
	}
	return (0);
}

int main()
{
    string	s;

    cin >> s;
    if (!ft_check_str(s))
	    cout << "YES";
    else
	    cout << "NO";
    return 0;
}
