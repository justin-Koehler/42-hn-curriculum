/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:40:22 by jukohler          #+#    #+#             */
/*   Updated: 2026/07/06 16:48:05 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res = 0;
	int	sign = 1;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*str++ == '-');
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}
