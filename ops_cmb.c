/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/15 19:49:35 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
	stacks->operations[SS]++;
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
	stacks->operations[RR]++;
}

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
	stacks->operations[RRR]++;
}
