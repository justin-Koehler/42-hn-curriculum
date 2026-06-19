/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:10:23 by eneumann          #+#    #+#             */
/*   Updated: 2026/02/11 11:58:35 by eneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power > 0)
		result *= nb * ft_recursive_power(nb, --power);
	return (result);
}
/*
int	main(int argc, char **argv)
{
	int	result;

	result = ft_recursive_power(atoi(argv[1]), atoi(argv[2]));
	printf("%d", result);
	return (0);
}*/
