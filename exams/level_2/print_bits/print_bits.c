#include <unistd.h>

void    print_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char	bit = 0;
	while (i >= 0)
	{
		bit = (octet >> i-- & 1) + 48;
		write(1, &bit, 1);
	}
}
/*
int	main(void)
{
	unsigned char	c = 255;
	print_bits(c);
}*/
