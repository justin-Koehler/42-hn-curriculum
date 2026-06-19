/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:16:57 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:32:21 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	char	t1 = 'a';
// 	char	t2 = 'z';
// 	char	t3 = 'M';
// 	char	t4 = '?';

// 	printf("a -> %c\n", ft_toupper(t1));
// 	printf("z -> %c\n", ft_toupper(t2));
// 	printf("M -> %c\n", ft_toupper(t3));
// 	printf("? -> %c\n", ft_toupper(t4));

// 	return (0);
// }