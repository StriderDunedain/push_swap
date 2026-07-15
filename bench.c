/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:11:04 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/15 19:43:18 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_benchmarks(t_stack *push_swap)
{
	ft_printf(STDERR_FILENO, "[bench] disorder:  %.2f\n", push_swap->disorder);
	ft_printf(STDERR_FILENO, "[bench] strategy:  %s\n", push_swap->strategy);
	ft_printf(STDERR_FILENO, "[bench] total_ops:  %i\n", push_swap->total_ops);
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "sa:  %i  ", push_swap->operations[SA]);
	ft_printf(STDERR_FILENO, "sb:  %i  ", push_swap->operations[SB]);
	ft_printf(STDERR_FILENO, "ss:  %i  ", push_swap->operations[SS]);
	ft_printf(STDERR_FILENO, "pa:  %i  ", push_swap->operations[PA]);
	ft_printf(STDERR_FILENO, "pb:  %i\n", push_swap->operations[PB]);
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "ra:  %i  ", push_swap->operations[RA]);
	ft_printf(STDERR_FILENO, "rb:  %i  ", push_swap->operations[RB]);
	ft_printf(STDERR_FILENO, "rr:  %i  ", push_swap->operations[RR]);
	ft_printf(STDERR_FILENO, "rra:  %i  ", push_swap->operations[RRA]);
	ft_printf(STDERR_FILENO, "rrb:  %i  ", push_swap->operations[RRB]);
	ft_printf(STDERR_FILENO, "rrr:  %i", push_swap->operations[RRR]);
}
