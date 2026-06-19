/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarkas <zfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:46:30 by zfarkas           #+#    #+#             */
/*   Updated: 2026/01/29 18:05:58 by zfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>*/

void	ft_ft(int *nbr);

/*int	main(void)
{
	int	number;

	number = 9;
	printf("a %p cimen a %i talalhato", &number, number);
	ft_ft(&number);
	printf("a funkcio hivas utan %p cimen a %i talalhato", &number, number);
	return (0);
}*/

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
