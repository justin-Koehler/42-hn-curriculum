/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:02:02 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/03 18:17:29 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *destiny;
	unsigned const char *source;
	destiny = (unsigned char *)dst;
	source = (unsigned const char *)src;
	if(dst != src)
		while (n--)
			*destiny++ = *source++;
	return dst;
}