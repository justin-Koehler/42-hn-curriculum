/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:19:39 by eneumann          #+#    #+#             */
/*   Updated: 2026/02/11 18:51:37 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_recursive_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	if (nb > 0)
		result *= ft_recursive_factorial(--nb);
	return (result);
}
/*
int	main(int argc, char **argv)
{
	int	result;

	result = ft_recursive_factorial(atoi(argv[1]));
	printf("%d", result);
	return (0);
}*/
