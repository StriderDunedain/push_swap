/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:12:50 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/22 00:07:41 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

void	set_ps(t_stack *ps)
{
	size_t	i;

	ps->strategy = NULL;
	ps->disorder = 0;
	ps->a = NULL;
	ps->b = NULL;
	ps->total_ops = 0;
	ps->bench = false;
	ps->algo = ALGO_NONE;
	i = 0;
	while (i < OP_COUNT)
		ps->operations[i++] = 0;
}

void	assign_ranks(t_list *a)
{
	t_list	*cur;
	t_list	*node;
	int		rank;

	cur = a;
	while (cur)
	{
		rank = 0;
		node = a;
		while (node)
		{
			if (node->value < cur->value)
				++rank;
			node = node->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

void	print_bench(t_stack *ps)
{
	int		hundredths;
	char	*stringed;

	hundredths = (int)(ps->disorder * 10000 + 0.5);
	stringed = ft_itoa(hundredths / 100);
	if (!stringed)
		return ;
	ft_printf(STDERR_FILENO,
		"[bench] disorder:  %s.%i%i%%\n"
		"[bench] strategy:   %s / %s\n"
		"[bench] total_ops:  %i\n"
		"[bench] sa: %i  sb: %i  ss: %i  pa: %i  pb: %i\n"
		"[bench] ra: %i  rb: %i  rr: %i  rra: %i  rrb: %i  rrr: %i\n",
		stringed, (hundredths % 100) / 10, (hundredths % 100) % 10,
		ps->strategy, ps->complexity, ps->total_ops, ps->operations[SA],
		ps->operations[SB], ps->operations[SS], ps->operations[PA],
		ps->operations[PB], ps->operations[RA], ps->operations[RB],
		ps->operations[RR], ps->operations[RRA], ps->operations[RRB],
		ps->operations[RRR]);
	free(stringed);
}

bool	is_empty_argument(char *s)
{
	while (*s)
	{
		if (!(*s == ' ' || *s == '\n' || *s == '\t'
				|| *s == '\v' || *s == '\f' || *s == '\r'))
			return (false);
		++s;
	}
	return (true);
}
