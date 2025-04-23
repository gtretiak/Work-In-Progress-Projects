/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:43:26 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/05 08:52:59 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main()
{
	char a = '?';
	char words[] = "Above just a character (symbol).\nHello World! (this part is array of char variables - size depends on number of characters)";
	printf("%c\n", a);
	printf("%s\n", words);
	printf("we can print as many words as we need in quotes");
	return(0);
}
