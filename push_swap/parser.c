/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 16:06:21 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/12 18:57:52 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(t_stack *stack, int num)
{
	while (stack && stack->value != num)
		stack = stack->next;
	return (stack != NULL);
}

static void	handle_parse_error(t_stack **stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	init_program(char **argv, t_stack **stack_a)
{
	t_stack	*new;
	int		val;
	int		error;

	while (*argv)
	{
		error = 0;
		val = ft_atoi(*argv, &error);
		if (error || has_duplicate(*stack_a, val))
			handle_parse_error(stack_a);
		new = malloc(sizeof(t_stack));
		if (!new)
			handle_parse_error(stack_a);
		new->value = val;
		new->index = -1;
		new->next = NULL;
		stack_add_back(stack_a, new);
		argv++;
	}
}
