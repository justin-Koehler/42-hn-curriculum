/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:48:28 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/05 13:06:53 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	if (!dst && dstsize == 0)
		return ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return dstsize + ft_strlen(src);
	return dst_len + ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	
}