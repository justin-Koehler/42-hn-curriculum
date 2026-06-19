/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:05:00 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/11 17:19:33 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]);
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

int	copy_str(char *dest, char *src, int pos)
{
	int	i;

	i = 0;
	while (src[i])
		dest[pos++] = src[i++];
	return (pos);
}

char	*join_strings(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		pos = copy_str(result, strs[i], pos);
		if (i < size - 1)
			pos = copy_str(result, sep, pos);
		i++;
	}
	result[pos] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	if (size == 0)
		return (malloc(1));
	result = malloc(get_total_len(size, strs, sep) + 1);
	if (!result)
		return (NULL);
	return (join_strings(size, strs, sep, result));
}
