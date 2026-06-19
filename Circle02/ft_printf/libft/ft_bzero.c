/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:17:23 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:27:47 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*clean;
	size_t			i;

	clean = s;
	i = 0;
	while (i < n)
	{
		clean[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	str1[] = "ABC";
// 	char	str2[] = "ABC";
// 	int		i;

// 	ft_bzero(str1 + 1, 1);
// 	bzero(str2 + 1, 1);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("ft_bzero: %d | bzero: %d\n", str1[i], str2[i]);
// 		i++;
// 	}
// 	return (0);
// }