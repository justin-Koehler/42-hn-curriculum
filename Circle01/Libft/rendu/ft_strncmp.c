/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:53:37 by jukohler          #+#    #+#             */
/*   Updated: 2026/07/06 16:39:17 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if(n == 0)
		return 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if(s1 && s2 && s1 == s2)
			i++;
		else
			return 0;
	}
}