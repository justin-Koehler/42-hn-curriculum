/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:30:10 by eneumann          #+#    #+#             */
/*   Updated: 2026/02/11 15:59:55 by eneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb);
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
int	main(int argc, char **argv)
{
	printf("%d", ft_find_next_prime(atoi(argv[1])));
	return (0);
}*/
