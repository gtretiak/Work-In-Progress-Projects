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

int	bitwiseAnd(int N, int K)
{
	int	a;
	int	b;
	int	res;

	a = 1;
	res = 0;
	while (a < N)
	{
		b = a + 1;
		while (b <= N)
		{
			if (res < (a & b) && (a & b) < K)
				res = (a & b);
			b++;
		}
		a++;
	}
	return (res);
}

int main()
{
//    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    printf("Enter the number of test-cases:");
    int t = parse_int(ltrim(rtrim(readline())));
    for (int t_itr = 0; t_itr < t; t_itr++) {
    	printf("Test %d:\nEnter as two space-separated integers:\n"
		"1) the max 'B' to consider and 2) the limit of the result:", t_itr + 1);
	char** first_multiple_input = split_string(rtrim(readline()));
        int count = parse_int(*(first_multiple_input + 0));
        int lim = parse_int(*(first_multiple_input + 1));
        int res = bitwiseAnd(count, lim);
	printf("The maximum value of A & B within the limit:\n%d\n\n", res);
        //fprintf(fptr, "%d\n", res);
    }
//    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

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

        data = realloc(data, alloc_length);

        if (!data) {
            data = NULL;

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = NULL;
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = NULL;
        } else {
            data[data_length] = '\0';
        }
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
