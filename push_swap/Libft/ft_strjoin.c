/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:37:35 by jukohler          #+#    #+#             */
/*   Updated: 2026/05/19 13:37:35 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, size + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}
