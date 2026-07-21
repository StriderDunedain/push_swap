/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/22 01:42:32 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *ps)
{
	sa(ps);
	sb(ps);
	ps->operations[SS]++;
	ps->total_ops++;
	ft_printf(STDOUT_FILENO, "ss\n");
}

void	rr(t_stack *ps)
{
	ra(ps);
	rb(ps);
	ps->operations[RR]++;
	ps->total_ops++;
	ft_printf(STDOUT_FILENO, "rr\n");
}

void	rrr(t_stack *ps)
{
	rra(ps);
	rrb(ps);
	ps->operations[RRR]++;
	ps->total_ops++;
	ft_printf(STDOUT_FILENO, "rrr\n");
}
