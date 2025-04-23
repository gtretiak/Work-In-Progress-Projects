/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:27:21 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/08 22:57:29 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
        while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		printf("%p - src[%d] = %c\n",&src[i],i,src[i]);
		i++;
	}
	return (i);
}

int	main ()
{
	char    output[] = "";
        char    source[7] = "01234567";
        unsigned int    len = (sizeof(source) / sizeof(source[0]));

        printf("Output by default: %s\n", output);
        printf("Your text: %s; Length of source: %d\n", source, len);
        printf("Output after: %s, length after: %d\n", output, ft_strlcpy(output, source, len));
	printf("Address of source is %p\n",&source[0]);
	printf("Address of output is %p\n",&output[0]);
	
	char output2[] = "";
	char source2[8] = "01234567";
	len = sizeof(source2) / sizeof(source2[0]);

	printf("Call to function itself: %d\n",strlcpy(output2, source2, len));
	printf("After call tpo function itself: %s\n",output2);
}
