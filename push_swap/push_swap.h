/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:45:00 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/12 18:11:01 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define MODE_SIMPLE	1
# define MODE_MEDIUM	2
# define MODE_COMPLEX	3
# define MODE_ADAPTIVE	4

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int	active;
	int	total_ops;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

void	init_program(char **argv, t_stack **stack_a);

int		stack_size(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
double	compute_disorder(t_stack *stack);

void	swap(t_stack **stack);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	normalize_indices(t_stack *stack);

void	exec_swap(t_stack **a, t_stack **b, char type, t_bench *bnch);
void	exec_push(t_stack **dest, t_stack **src, char type, t_bench *bnch);
void	exec_rotate(t_stack **a, t_stack **b, char type, t_bench *bnch);
void	exec_rev_rotate(t_stack **a, t_stack **b, char type, t_bench *bnch);
void	print_bench_results(t_bench *b, t_stack *a);

void	execute_strategy(t_stack **a, t_stack **b, t_bench *bnch, int mode);

#endif
