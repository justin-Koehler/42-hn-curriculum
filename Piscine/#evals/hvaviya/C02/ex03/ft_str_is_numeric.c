/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaviya <hvaviya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:35:53 by hvaviya           #+#    #+#             */
/*   Updated: 2026/02/01 18:03:02 by hvaviya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	is_numeric(char c)
{
	if (('0' <= c && c <= '9'))
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!is_numeric(str[counter]))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}
