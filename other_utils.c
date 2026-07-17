/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:12:50 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/17 15:03:26 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rank_node(t_list *target, t_list *a)
{
	t_list	*node;
	int		rank;

	rank = 0;
	node = a;
	while (node)
	{
		if (node->value < target->value)
			++rank;
		node = node->next;
	}
	target->index = rank;
}

void	assign_ranks(t_list *a)
{
	t_list	*cur;

	cur = a;
	while (cur)
	{
		rank_node(cur, a);
		cur = cur->next;
	}
}

static void	print_disorder(double disorder)
{
	int		hundredths;
	char	*stringed;
	char	buf[3];

	hundredths = (int)(disorder * 10000 + 0.5);
	stringed = ft_itoa(hundredths / 100);
	buf[0] = '0' + (hundredths % 100) / 10;
	buf[1] = '0' + (hundredths % 100) % 10;
	buf[2] = '\0';
	ft_printf(STDERR_FILENO, "[bench] disorder:  ");
	ft_printf(STDERR_FILENO, stringed);
	ft_printf(STDERR_FILENO, ".");
	write(STDERR_FILENO, buf, 2);
	ft_printf(STDERR_FILENO, "\n");
	free(stringed);
}

void	get_benchmarks(t_stack *ps)
{
	print_disorder(ps->disorder);
	ft_printf(STDERR_FILENO, "[bench] strategy:  %s\n", ps->strategy);
	ft_printf(STDERR_FILENO, "[bench] total_ops:  %i\n", ps->total_ops);
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "sa:  %i  ", ps->operations[SA]);
	ft_printf(STDERR_FILENO, "sb:  %i  ", ps->operations[SB]);
	ft_printf(STDERR_FILENO, "ss:  %i  ", ps->operations[SS]);
	ft_printf(STDERR_FILENO, "pa:  %i  ", ps->operations[PA]);
	ft_printf(STDERR_FILENO, "pb:  %i\n", ps->operations[PB]);
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "ra:  %i  ", ps->operations[RA]);
	ft_printf(STDERR_FILENO, "rb:  %i  ", ps->operations[RB]);
	ft_printf(STDERR_FILENO, "rr:  %i  ", ps->operations[RR]);
	ft_printf(STDERR_FILENO, "rra:  %i  ", ps->operations[RRA]);
	ft_printf(STDERR_FILENO, "rrb:  %i  ", ps->operations[RRB]);
	ft_printf(STDERR_FILENO, "rrr:  %i", ps->operations[RRR]);
}
