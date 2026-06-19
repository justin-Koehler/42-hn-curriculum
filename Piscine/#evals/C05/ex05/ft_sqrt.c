/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:42:53 by eneumann          #+#    #+#             */
/*   Updated: 2026/02/11 13:58:04 by eneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	principal;

	principal = 0;
	while (principal * principal <= nb
		&& principal * principal <= 2147483647)
	{
		if (principal * principal == nb)
			return (principal);
		principal++;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int	result;

	result = ft_sqrt(atoi(argv[1]));
	printf("%d", result);
	return (0);
}*/
