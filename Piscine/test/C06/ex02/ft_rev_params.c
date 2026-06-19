/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:29:28 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/01 17:29:30 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		arg_index;
	char	*s;

	arg_index = argc - 1;
	while (arg_index > 0)
	{
		s = argv[arg_index];
		while (*s)
			write(1, s++, 1);
		write(1, "\n", 1);
		arg_index--;
	}
	return (0);
}
