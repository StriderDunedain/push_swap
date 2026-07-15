/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/15 20:41:21 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
	stacks->operations[SS]++;
	ft_printf(STDOUT_FILENO, "ss\n");
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
	stacks->operations[RR]++;
	ft_printf(STDOUT_FILENO, "rr\n");
}

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
	stacks->operations[RRR]++;
	ft_printf(STDOUT_FILENO, "rrr\n");
}
