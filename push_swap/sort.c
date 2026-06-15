/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:15:00 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/12 18:47:24 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	strategy_simple(t_stack **a, t_stack **b, t_bench *bnch)
{
	int	top;
	int	mid;
	int	bot;

	if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
		exec_swap(a, b, 'a', bnch);
	if (stack_size(*a) != 3 || is_sorted(*a))
		return ;
	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		exec_swap(a, b, 'a', bnch);
	else if (top > mid && mid > bot)
		(exec_swap(a, b, 'a', bnch), exec_rev_rotate(a, b, 'a', bnch));
	else if (top > mid && mid < bot && top > bot)
		exec_rotate(a, b, 'a', bnch);
	else if (top < mid && mid > bot && top < bot)
		(exec_swap(a, b, 'a', bnch), exec_rotate(a, b, 'a', bnch));
	else if (top < mid && mid > bot && top > bot)
		exec_rev_rotate(a, b, 'a', bnch);
}

static void	strategy_medium(t_stack **a, t_stack **b, t_bench *bnch)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size && !is_sorted(*a))
	{
		if ((*a)->index < size - 3)
			exec_push(b, a, 'b', bnch);
		else
			exec_rotate(a, b, 'a', bnch);
		i++;
	}
	strategy_simple(a, b, bnch);
	while (*b)
		exec_push(a, b, 'a', bnch);
}

static void	strategy_complex(t_stack **a, t_stack **b, t_bench *bnch)
{
	int	bit;
	int	size;
	int	i;

	bit = 0;
	size = stack_size(*a);
	while (bit < 9 && !is_sorted(*a))
	{
		i = 0;
		while (i++ < size)
		{
			if (((*a)->index >> bit) & 1)
				exec_rotate(a, b, 'a', bnch);
			else
				exec_push(b, a, 'b', bnch);
		}
		while (*b)
			exec_push(a, b, 'a', bnch);
		bit++;
	}
}

static void	strategy_adaptive(t_stack **a, t_stack **b, t_bench *bnch)
{
	double	disorder;
	int		size;

	size = stack_size(*a);
	if (size <= 3)
	{
		strategy_simple(a, b, bnch);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 20.0)
		strategy_simple(a, b, bnch);
	else if (disorder < 50.0)
		strategy_medium(a, b, bnch);
	else
		strategy_complex(a, b, bnch);
}

void	execute_strategy(t_stack **a, t_stack **b, t_bench *bnch, int mode)
{
	if (!a || !*a || is_sorted(*a))
		return ;
	if (mode == 1)
		strategy_simple(a, b, bnch);
	else if (mode == 2)
		strategy_medium(a, b, bnch);
	else if (mode == 3)
		strategy_complex(a, b, bnch);
	else if (mode == 4)
		strategy_adaptive(a, b, bnch);
}
