// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/06/12 15:17:45 by jukohler          #+#    #+#             */
// /*   Updated: 2026/06/16 17:04:53 by jukohler         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static int	check_flags(char *arg, t_bench *b, int *mode)
// {
// 	if (!arg || arg[0] != '-' || arg[1] != '-')
// 		return (0);
// 	if (arg[2] == 'b' && arg[3] == 'e')
// 	{
// 		b->active = 1;
// 		return (1);
// 	}
// 	if (arg[2] == 's')
// 		*mode = 1;
// 	else if (arg[2] == 'm')
// 		*mode = 2;
// 	else if (arg[2] == 'c')
// 		*mode = 3;
// 	else if (arg[2] == 'a')
// 		*mode = 4;
// 	else
// 		return (0);
// 	return (1);
// }

// /*
// ** Local debug utility to verify sorting results on stdout
// */
// static void	debug_verify_status(t_stack *a)
// {
// 	// Zum lokalen Testen einkommentieren, vor Abgabe loeschen!
// 	// if (is_sorted(a))
// 	// 	write(1, "\033[1;32m[OK] Sorted\033[0m\n", 22);
// 	// else
// 	// 	write(1, "\033[1;31m[KO] Unsorted\033[0m\n", 24);
// 	(void)a;
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	t_bench	bnch;
// 	int		mode;

// 	a = NULL;
// 	b = NULL;
// 	mode = 4;
// 	if (argc < 2)
// 		return (0);
// 	ft_bzero(&bnch, sizeof(t_bench));
// 	argv++;
// 	// Erlaubt das Verarbeiten und saubere Überspringen beliebig vieler Flags
// 	while (*argv && check_flags(*argv, &bnch, &mode))
// 		argv++;
// 	// Falls nach den Flags noch Zahlen übrig sind, startet das reguläre Parsing
// 	if (*argv)
// 	{
// 		init_program(argv, &a);
// 		normalize_indices(a); // Zwingend erforderlich fuer den Complex-Modus
// 	}
// 	if (a && !is_sorted(a))
// 		execute_strategy(&a, &b, &bnch, mode);
// 	if (bnch.active)
// 		print_bench_results(&bnch, a);
// 	debug_verify_status(a);
// 	return (free_stack(&a), 0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:17:45 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/16 17:15:22 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flags(char *arg, t_bench *b, int *mode)
{
	if (!arg || arg[0] != '-' || arg[1] != '-')
		return (0);
	if (arg[2] == 'b')
	{
		b->active = 1;
		return (1);
	}
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

/*
** Local debug utility to verify sorting results on stdout.
** Green [OK] indicates a perfectly sorted stack.
** Red [KO] signals an algorithm configuration error.
*/
static void	debug_verify_status(t_stack *a)
{
	write(1, "\n========================================\n", 42);
	if (is_sorted(a))
	{
		write(1, "\033[1;32m[OK] Stack is perfectly sorted.\033[0m\n", 42);
	}
	else
	{
		write(1, "\033[1;31m[KO] Stack is still unsorted!\033[0m\n", 41);
	}
	write(1, "========================================\n", 41);
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
	{
		init_program(argv, &a);
		normalize_indices(a);
	}
	if (a && !is_sorted(a))
		execute_strategy(&a, &b, &bnch, mode);
	if (bnch.active)
		print_bench_results(&bnch, a);
	
	/* Displays execution confirmation for local testing matrix */
	debug_verify_status(a);
	
	return (free_stack(&a), 0);
}
