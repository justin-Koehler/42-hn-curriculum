/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutter <lhutter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:48:45 by lhutter           #+#    #+#             */
/*   Updated: 2026/02/10 13:57:32 by lhutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*out;
	int	i;

	if (min >= max)
		return (0);
	range = max - min;
	out = (int *)malloc(sizeof(int) * range);
	if (!out)
		return (0);
	i = 0;
	while (min < max)
	{
		out[i] = min;
		min++;
		i++;
	}
	return (out);
}
