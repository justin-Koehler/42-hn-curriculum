/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:17:45 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/12 18:57:35 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flags(char *arg, t_bench *b, int *mode)
{
	if (!arg || arg[0] != '-' || arg[1] != '-')
		return (0);
	if (arg[2] == 'b' && arg[3] == 'e')
		return (b->active = 1);
	if (arg[2] == 's')
		*mode = 1;
	else if (arg[2] == 'm')
		*mode = 2;
	else if (arg[2] == 'c')
		*mode = 3;
	else if (arg[2] == 'a')
		*mode = 4;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bnch;
	int		mode;

	a = NULL;
	b = NULL;
	mode = 4;
	if (argc < 2)
		return (0);
	ft_bzero(&bnch, sizeof(t_bench));
	argv++;
	while (*argv && check_flags(*argv, &bnch, &mode))
		argv++;
	if (*argv)
		init_program(argv, &a);
	if (a && !is_sorted(a))
		execute_strategy(&a, &b, &bnch, mode);
	if (bnch.active)
		print_bench_results(&bnch, a);
	return (free_stack(&a), 0);
}
