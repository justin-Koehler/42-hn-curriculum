/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:23:06 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:26:18 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

// int main(void)
// {
//     size_t count = 5;
//     size_t size = sizeof(int);
//     size_t total = count * size;

//     unsigned char *a = ft_calloc(count, size);
//     unsigned char *b = calloc(count, size);
//     if (!a || !b)
//         return 1;
//     size_t i = 0;
//     while (i < total)
//     {
//         printf("ft: %u | real: %u\n", a[i], b[i]);
//         i++;
//     }
//     free(a);
//     free(b);
//     return 0;
// }