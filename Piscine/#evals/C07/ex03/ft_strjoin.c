/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutter <lhutter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:32:20 by lhutter           #+#    #+#             */
/*   Updated: 2026/02/11 14:35:06 by lhutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
}

int	get_size(char *str)
{
	int	out;
	int	i;

	i = 0;
	out = 0;
	while (str[i])
	{
		out += sizeof(str[i]);
		i++;
	}
	return (out);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	length = 0;
	while (i < size)
		length += get_size(strs[i++]);
	if (size > 0)
		length += ((size - 1) * get_size(sep)) + 1;
	out = (char *)malloc(length);
	if (!out)
		return (0);
	while (j < size)
	{
		ft_strcat(out, strs[j]);
		if (j < size - 1)
			ft_strcat(out, sep);
		j++;
	}
	out[length] = '\0';
	return (out);
}
