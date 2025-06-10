#include <stdio.h>

int main()
{
int	a;
int	b;
int	c;

scanf("%d %d %d", &a, &b, &c);
if (a >= b && b <= c && a <= c)
	printf("%d", a);
else if (a >= b && b <= c && a >= c)
	printf("%d", c);
else
{
	if (b > c)
		printf("%d", c);
	else
		printf("%d", b);	
}
}
