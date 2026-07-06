/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:48:37 by jukohler          #+#    #+#             */
/*   Updated: 2026/07/06 16:51:42 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	total = nmemb * size;
	if (nmemb && total / nmemb != size)
		return (NULL);
	ptr = malloc(total);
	if (ptr)
		ft_bzero(ptr, total);
	return (ptr);
}
