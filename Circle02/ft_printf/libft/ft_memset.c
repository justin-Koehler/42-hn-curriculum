/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:56:40 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:58:14 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)b;
	while (len-- > 0)
	{
		*temp = (unsigned char)c;
		temp++;
	}
	return (b);
}

// int	main(void)
// {
// 	char	str[10];
// 	size_t	i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		str[i] = 'A';
// 		i++;
// 	}

// 	printf("Before memset: %s\n", str);

// 	ft_memset(str, 'X', 5);

// 	printf("After memset : %s\n", str);

// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("str[%zu] = %c\n", i, str[i]);
// 		i++;
// 	}

// 	return (0);
// }