#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char    *ft_double_string(char *s)
{
    char *res;
    res = malloc(sizeof(char) * strlen(s) * 2 + 1);
    int i = 0;
    int j = 0;
    while (s[i])
    {
        res[i] = s[i];
        i++;
    }
    while (s[j])
    {
        res[i + j] = s[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);  
}

int ft_get_starting_points(char *s, char *goal)
{
    int res = 0;
    int i = 0;
    while (s[i])
    {
        if (*goal == s[i])
            res++;
        i++;
    }
    return (res);
}

bool rotateString(char* s, char* goal) {
    if (strlen(s) != strlen(goal))
        return (false);
    char *str;
    str = ft_double_string(s);
    int i = 0;
    int j;
    int n;
    n = ft_get_starting_points(s, goal);
    if (n == 0)
        return (false);
    while (n)
    {
    while (goal[0] != str[i])
        i++;
    j = 0;
    while (goal[j])
    {
        if (goal[j] != str[i + j])
        {
            if (n)
            {
                n--;
                i++;
                break ;
            }
            else
            {
                free(str);
                return (false);
            }
        }
        j++;
    }
    if (!goal[j])
        return (true);
    n--;
    }
    free(str);
    return (true);
}

int	main(void)
{
	char *s1 = "bbbacddceeb";
	char *s2 = "ceebbbbacdd";
	bool is_true;
	is_true = rotateString(s1, s2);
	if (is_true)
		printf("True");
	else
		printf("False");
}
