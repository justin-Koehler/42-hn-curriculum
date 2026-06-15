/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:37:26 by jukohler          #+#    #+#             */
/*   Updated: 2026/05/19 13:37:26 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc(ft_strlen(s) + 1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}
