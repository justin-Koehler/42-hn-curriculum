/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:30:56 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:30:58 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int main(void)
// {
//     int tests[] = {
//         'A', 'Z', 'a', 'z',
//         '0', '9',
//         '@', ' ', '-', 'g', 'G', '5',
//         0, 127, 128
//     };

//     size_t i = 0;
//     size_t len = sizeof(tests) / sizeof(tests[0]);

// 	while (i < len)
//     {
//         int c = tests[i];

//     	printf("input: %d | ft: %d | real: %d\n", c,
//     	ft_isascii(c),
//     	isascii(c));

//         i++;
//     }
// }