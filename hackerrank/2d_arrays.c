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

# define SIZE 6

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

void    ft_free_arr(int    **arr)
{
    int    i;

    i = 0;
    while (i < 6)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int    ft_calculate(int **arr, int size)
{
    int    res;
    int    tmp;
    int    i;
    int    j;

    i = 0;
    res = -100;
    while (i <= size - 3)
    {
        j = 0; 
        while (j <= size - 3)
        {
            tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2]
                + arr[i + 1][j + 1] + arr[i + 2][j]
                + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            if (tmp > res)
                res = tmp;
            j++;
        }
        i++;
    }
    return (res);
}

int main()
{
    int    res;
    int** arr = malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = malloc(SIZE * (sizeof(int)));

        char** arr_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < SIZE; j++) {
            int arr_item = parse_int(*(arr_item_temp + j));
            *(*(arr + i) + j) = arr_item;
        }
    }
    res = ft_calculate(arr, SIZE);
    printf("%d", res);
    ft_free_arr(arr);
    return (0);
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break ;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break ;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = NULL;

            break ;
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

    return (data);
}

char* ltrim(char* str) {
    if (!str) {
        return (NULL);
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
        return (NULL);
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
