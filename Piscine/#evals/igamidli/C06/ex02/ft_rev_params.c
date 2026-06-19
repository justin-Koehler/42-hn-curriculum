/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igamidli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:17:43 by igamidli          #+#    #+#             */
/*   Updated: 2026/02/09 20:18:45 by igamidli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	right;

	i = 1;
	right = argc - 1;
	while (i < argc)
	{
		j = 0;
		while (argv[right][j])
		{
			ft_putchar(argv[right][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		right--;
	}
}
