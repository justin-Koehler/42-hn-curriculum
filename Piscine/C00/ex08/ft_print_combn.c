/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:25:56 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/11 17:42:56 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int *arr, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (arr[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;
	int	j;

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (++i < n)
		arr[i] = i;
	while (arr[0] <= 10 - n)
	{
		print_comb(arr, n);
		arr[n - 1]++;
		i = n - 1;
		while (i > 0 && arr[i] > 9 - (n - 1 - i))
		{
			i--;
			arr[i]++;
			j = i;
			while (++j < n)
				arr[j] = arr[j - 1] + 1;
		}
	}
}
