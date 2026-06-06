/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:20:13 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/03 19:12:16 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *destiny;
	unsigned const char *source;
	if(!dest && !src)
		return NULL;
	destiny = (unsigned char *)dest;
	source = (unsigned const char *)src;
	if (dest > src)
		while(n--)
			destiny[n] = source[n];
	else
		ft_memcpy(dest, src, n);		
	return dest;
}