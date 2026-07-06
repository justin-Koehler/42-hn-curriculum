/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:42:10 by jukohler          #+#    #+#             */
/*   Updated: 2026/07/06 15:51:21 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
	char *result;
	
	result = malloc(ft_strlen(s1) + 1);
	if(!result)
		return NULL;
	ft_strcpy(result, s1);
	return result;
}