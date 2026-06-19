/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:29:39 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/01 17:29:40 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	string_compare(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

static void	print_string(char *string)
{
	while (*string)
		write(1, string++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*t;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (string_compare(argv[j], argv[j + 1]) > 0)
			{
				t = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
		print_string(argv[i++]);
	return (0);
}
