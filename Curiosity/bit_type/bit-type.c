/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit-type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:51:41 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/23 12:53:06 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

int main() {
    printf("Size of a pointer: %zu bytes\n", sizeof(void *));
    printf("Size of uintptr_t: %zu bytes\n", sizeof(uintptr_t));
    return 0;
}


