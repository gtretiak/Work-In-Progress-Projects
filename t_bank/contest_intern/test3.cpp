#include <iostream>
using namespace std;

int	ft_calculate(int start, int pause, int arrived)
{
	int	k;

	if (arrived <= start)
		return (start);
	k = (arrived - start + pause - 1) / pause;
	pause *= k;
	return (start + pause);
}

int main()
{
    int	total_l;
    int	n_quer;
    int	i;
    int	*t_dep;
    int	*t_wait;
    int	*t_quer;
    int	*num_l;
    cin >> total_l;
    i = 0;
    t_dep = new int[total_l];
    t_wait = new int[total_l];
    while (i < total_l)
    {
	    cin >> t_dep[i];
	    cin >> t_wait[i];
	    i++;
    }
    i = 0;
    cin >> n_quer;
    num_l = new int[n_quer];
    t_quer = new int[n_quer];
    while (i < n_quer)
    {
	    cin >> num_l[i];
	    cin >> t_quer[i];
	    i++;
    }
    i = 0;
    while (i < n_quer)
    {
	    cout << ft_calculate(t_dep[num_l[i] - 1], t_wait[num_l[i] - 1], t_quer[i]) << endl;
	    i++;
    }
    delete[] t_dep;
    delete[] t_wait;
    delete[] num_l;
    delete[] t_quer;
    return 0;
}
