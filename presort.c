/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:12:50 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/16 20:13:01 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Step 1: assign ranks (indexes) to each node.
** Rank = how many nodes have a smaller value.
** After this, node->index is the node's sorted position (0-based).
*/

static void	rank_node(t_list *target, t_list *a)
{
	t_list	*cur;
	int		rank;

	rank = 0;
	cur = a;
	while (cur)
	{
		if (cur->value < target->value)
			++rank;
		cur = cur->next;
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