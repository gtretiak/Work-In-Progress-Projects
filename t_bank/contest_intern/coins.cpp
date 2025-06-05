#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

unsigned long long	ft_calculate_num_options(unsigned long long sum, int a, int b, int c)
{
	unsigned long long	total;
	unsigned long long	current_dist;
	unsigned long long	new_dist;
	unsigned long long	max_k;
	vector<unsigned long long>	dp(c, ULLONG_MAX);
	int	x;
	int	new_x;
	// we use modulo c since the biggest nums dominate sums
	dp[1 % c] = 0; // starting point
	priority_queue<pair<long long, int>,
		vector<pair<long long, int>>,
		greater<pair<long long, int>>>	pq;
	pq.push({0, 1 % c});
	while (!pq.empty())
	{
		auto current = pq.top();
		pq.pop();
		current_dist = current.first;
		x = current.second;
		if (current_dist > dp[x])
			continue ;
		new_x = (x + a) % c;
		new_dist = current_dist + ((x + a >= c) ? 0 : 1);
		if (new_dist < dp[new_x])
		{
			dp[new_x] = new_dist;
			pq.push({new_dist, new_x});
		}
		new_x = (x + b) % c;
		new_dist = current_dist + ((x + b >= c) ? 0 : 1);
		if (new_dist < dp[new_x])
		{
			dp[new_x] = new_dist;
			pq.push({new_dist, new_x});
		}
	}
	total = 1;
	for (int i = 0; i < c; ++i)
	{
		if (dp[i] != ULLONG_MAX)
		{
			max_k = (sum - i) / c;
			if (max_k >= dp[i])
				total += max_k - dp[i] + 1;
		}
	}
	return (total);
}

int	main(void)
{
	unsigned long long	max_sum; //maximum sum to consider
	int	nums[3]; // three coins
	int	tmp;
	unsigned long long	num_options;
	cin >> max_sum >> nums[0] >> nums[1] >> nums[2];
	if (nums[0] > nums[1]) // sorting for efficiency in calculations a<=b<=c
		swap(nums[0], nums[1]);
	if (nums[1] > nums[2])
		swap(nums[1], nums[2]);
	if (nums[0] > nums[1])
		swap (nums[0], nums[1]);
	// let's find the number of valid sums
	num_options = ft_calculate_num_options(max_sum, nums[0], nums[1], nums[2]);
	cout << num_options << endl;
}
