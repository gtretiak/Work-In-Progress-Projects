#include <unistd.h>

/* we need to have a simple putnbr function for this one
 * since we'll be working with and printing numbers 
 */
void ft_putnbr(int i)
{
    /* if the number is greater than 9, we call the function again
     * with the number divided by 10 so that we remove one digit
     * from the end of it (123 => 12)
     */
    if (i > 9)
        ft_putnbr(i / 10);
    /* then we can print the character at the index i % 10 (123 => 3)
     * in a string containing all digits from 0-9
     */
    write(1, &"0123456789"[i % 10], 1);
    /* I'll explain what I wrote above :
     * in C, strings do not exist, when we store a string
     * we store an array of character terminated by a NUL-character
     * so what I did above, is writing a string, and then I did
     * the same thing you'd do to select an array element with the
     * square bracket to select a specific index
     * the second argument of the write function is a char *
     * that's why I added the & character in front of the string
     * That way I give to write() a pointer to the specific
     * character I want to write
     */
}

int main(void)
{
    int i;
    
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if  (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(i);
        i++;
        write(1, "\n", 1);
    }
}
