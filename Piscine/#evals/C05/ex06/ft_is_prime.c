/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:54:30 by eneumann          #+#    #+#             */
/*   Updated: 2026/02/11 15:27:17 by eneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb);

int	ft_is_prime(int nb)
{
	int	divisor;

	if (nb <= 1)
		return (0);
	divisor = 2;
	while (divisor <= nb / 2)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	printf("%d", ft_is_prime(atoi(argv[1])));
	return (0);
}*/
