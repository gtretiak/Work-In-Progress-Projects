#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

int	ft_compare_strings(const void *s1, const void *s2)
{
	return (strcmp(*(const char **)s1, *(const char **)s2));
}

void	ft_print_output(char **arr, int size)
{
	int	i;

	i = 0;
	qsort(arr, size, sizeof(const char *), ft_compare_strings);
	while (i < size)
		printf("%s\n", arr[i++]);
}

void	ft_free(char **arr, int strings_num, int arr_size)
{
	int	i;

	i = 0;
	while (i < strings_num)
		free(arr[i++]);
	while (i < arr_size)
		free(arr[i++]);
	free(arr);
}

bool	ft_check_email(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '@')
		i++;
	if (!strcmp(s + i, "@gmail.com"))
		return (true);
	return (false); 
}

int main()
{
    int N = parse_int(ltrim(rtrim(readline())));
    char	**output;
    int	i;

    i = 0;
    output = malloc(sizeof(char *) * N + 1);
    for (int N_itr = 0; N_itr < N; N_itr++) {
        char* line = rtrim(readline());
	char** first_multiple_input = split_string(line);
        char* firstName = *(first_multiple_input + 0);
        char* emailID = *(first_multiple_input + 1);
	if (ft_check_email(emailID))
	{
		output[i] = strdup(firstName);
		i++;
	}
	free(first_multiple_input);
	free(line);
    }
    output[i] = NULL;
    ft_print_output(output, i);
    ft_free(output, i, N);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    char* new_data;

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;
        new_data = realloc(data, alloc_length);

        if (!new_data) {
            free(data);
	    return (NULL);
        }
	data = new_data;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        new_data = realloc(data, data_length);

        if (!new_data) {
            free(data);
	    return (NULL);
        }
	data = new_data;
    } else {
        new_data = realloc(data, data_length + 1);

        if (!new_data) {
            free(data);
	    return (NULL);
        }
	data = new_data;
        data[data_length] = '\0';
        }
    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return NULL;
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return NULL;
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
