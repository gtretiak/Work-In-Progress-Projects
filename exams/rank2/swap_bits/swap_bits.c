#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
/*
void	print_bits(unsigned char octet)
{
	char	c;
	int	i = 7;
	while (i >= 0)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
		i--;
	}
}

#include <stdio.h>

int	main(void)
{
	unsigned char	c;
	int	x = 123;
	print_bits(x);
	write(1, "\n\n", 2);
	c = swap_bits(x);
	print_bits((int)c);
}*/
