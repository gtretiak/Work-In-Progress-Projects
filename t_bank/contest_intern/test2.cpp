#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int	n;
    int	i;
    int	x;
    i = 0;
    cin >> n;
    vector<int> a(n);
    while (i < n)
	    cin >> a[i++];
    sort(a.rbegin(), a.rend());
    set<int> used;
    i = 0;
    while (i < n)
    {
	    x = a[i];
	    while (x > 0 && used.count(x))
		    x /= 2;
	    if (!used.count(x))
		    used.insert(x);
	    i++;
    }
    cout << used.size() << endl;
    return 0;
}
