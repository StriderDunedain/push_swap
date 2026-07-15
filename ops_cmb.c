/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/15 21:46:11 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *push_swap)
{
	sa(push_swap);
	sb(push_swap);
	push_swap->operations[SS]++;
	handle_op(push_swap, "ss\n");
}

void	rr(t_stack *push_swap)
{
	ra(push_swap);
	rb(push_swap);
	push_swap->operations[RR]++;
	handle_op(push_swap, "rr\n");
}

void	rrr(t_stack *push_swap)
{
	rra(push_swap);
	rrb(push_swap);
	push_swap->operations[RRR]++;
	handle_op(push_swap, "rrr\n");
}
