/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/17 10:42:09 by aschinog         ###   ########.fr       */
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
