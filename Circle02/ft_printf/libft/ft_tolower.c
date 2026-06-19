/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:17:23 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:32:25 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	char	test1 = 'A';
// 	char	test2 = 'Z';
// 	char	test3 = 'm';
// 	char	test4 = '1';

// 	printf("A -> %c\n", ft_tolower(test1));
// 	printf("Z -> %c\n", ft_tolower(test2));
// 	printf("m -> %c\n", ft_tolower(test3));
// 	printf("1 -> %c\n", ft_tolower(test4));

// 	return (0);
// }
