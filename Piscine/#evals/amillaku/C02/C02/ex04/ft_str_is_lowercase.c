/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amillaku <amillaku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:18:22 by amillaku          #+#    #+#             */
/*   Updated: 2026/01/29 18:33:28 by amillaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z'))
		{
			str++;
		}
		else
			return (0);
	}
	return (1);
}
