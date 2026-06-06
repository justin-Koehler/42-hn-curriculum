/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:12:59 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/05 12:51:26 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t src_len;
	size_t i;

	src_len = ft_strlen(src);
	i = 0;
	if(dst_size == 0)
		return src_len;
	while (src[i] && i < dst_size - 1)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return src_len;
}
