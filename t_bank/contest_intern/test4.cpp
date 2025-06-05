#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> a;
int	arr[100][100];

int	ft_calculate(int l, int r)
{
	int	res;
	int	left;
	int	right;
	int	cost;

	res = 0;
	if (r <= l)
		return (0);
	if (l + 1 == r)
		return (abs(a[l] - a[r]));
	if (arr[l][r] != -1)
		return (arr[l][r]);
	for (int i = l + 1; i <= r; i += 2)
	{
		left = ft_calculate(l + 1, i - 1);
		right = ft_calculate(i + 1, r);
		cost = abs(a[l] - a[i]);
		res = max(res, left + cost + right);
	}
	arr[l][r] = res;
	return (res);
}

int main()
{
	int	num;
	int	i;
	cin >> num;
	a.resize(num);
	i = 0;
	while (i < num)
	{
		cin >> a[i];
		i++;
	}
	memset(arr, -1, sizeof(arr));
	cout << ft_calculate(0, num - 1) << endl;
	return 0;
}
