#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    int a;
    double b;
    char str[1024];
    char tmp[1024];
    scanf("%d", &a);
    fgets(str, 1024, stdin);
    b = atof(str);
    fgets(tmp, 1024, stdin);
    printf("%d\n", a + i);
    // Print the sum of both integer variables on a new line.
    printf("%.1f\n", d + b);
    // Print the sum of the double variables on a new line.
    printf("%s%s", s, tmp);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first
    return 0;
}
