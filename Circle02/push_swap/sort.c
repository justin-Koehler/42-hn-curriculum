/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:15:00 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/16 17:10:10 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strategy_simple(t_stack **a, t_stack **b, t_bench *bnch)
{
	int	top;
	int	mid;
	int	bot;

	if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
	{
		exec_swap(a, b, 'a', bnch);
		return ;
	}
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

static int	get_max_index_pos(t_stack *b)
{
	int		max_idx;
	int		max_pos;
	int		pos;

	max_idx = -1;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (b->index > max_idx)
		{
			max_idx = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

void	strategy_medium(t_stack **a, t_stack **b, t_bench *bnch)
{
	int	size;
	int	chunk_size;
	int	current_chunk;
	int	max_pos;

	size = stack_size(*a);
	chunk_size = size / 5;
	if (chunk_size == 0)
		chunk_size = 1;
	current_chunk = chunk_size;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index <= current_chunk)
		{
			exec_push(b, a, 'b', bnch);
			if (*b && (*b)->next && (*b)->index < (current_chunk - (chunk_size / 2)))
				exec_rotate(a, b, 'b', bnch);
		}
		else
			exec_rotate(a, b, 'a', bnch);
		if (stack_size(*b) >= current_chunk && current_chunk < size)
			current_chunk += chunk_size;
	}
	strategy_simple(a, b, bnch);
	while (*b)
	{
		max_pos = get_max_index_pos(*b);
		size = stack_size(*b);
		if (max_pos <= size / 2)
			while (max_pos--)
				exec_rotate(a, b, 'b', bnch);
		else
			while (max_pos++ < size)
				exec_rev_rotate(a, b, 'b', bnch);
		exec_push(a, b, 'a', bnch);
	}
}

void	strategy_complex(t_stack **a, t_stack **b, t_bench *bnch)
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

void	strategy_adaptive(t_stack **a, t_stack **b, t_bench *bnch)
{
	double	disorder;
	int		size;

	size = stack_size(*a);
	if (size <= 3)
	{
		strategy_simple(a, b, bnch);
		return ;
	}
	disorder = compute_disorder(*a); // Liefert jetzt exakt 0.0 bis 1.0
	if (disorder < 0.2) // Entspricht exakt der Vorgabe aus Kapitel VI.3.3
		strategy_simple(a, b, bnch);
	else if (disorder < 0.5)
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
