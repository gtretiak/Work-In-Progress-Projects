#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//vector<int> a;
//int	arr[100][100];
//cost = abs(a[l] - a[i]);
//res = max(res, left + cost + right);
//	a.resize(num);
//	memset(arr, -1, sizeof(arr));

int	ft_calculate(int *nums, int n)
{
	int	res;
	int	i;
	int	j;
	int	k;
	int	l;
	int	r;

	res = 0;
	l = 0;
	while (l < n)
	{
		r = l + 2;
		while (r < n)
		{
			i = 0;
			while (i < n)
			{
				k = i + 1;
				while (k < n)
				{
					j = k + 1;
					while (j < n)
					{
						if (nums[k] * 2 == nums[i] + nums[j])
							res++;
						j++;
					}
					k++;
				}
				i++;
			}
			r++;
		}
		l++;
	}
	return (res);
}

int main()
{
	int	n;
	int	*nums;
	int	i;
	cin >> n;
	nums = new int[n];
	i = 0;
	while (i < n)
	{
		cin >> nums[i];
		i++;
	}
	cout << ft_calculate(nums, n) << endl;
	delete[] nums;
	return 0;
}
