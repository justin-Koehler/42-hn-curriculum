/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:29:21 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/01 17:29:23 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*s;

	s = argv[0];
	(void)argc;
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
	return (0);
}
