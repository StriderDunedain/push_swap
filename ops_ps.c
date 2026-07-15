/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:58 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/15 21:46:11 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *push_swap)
{
	int		tmp_value;
	int		tmp_index;

	if (!push_swap || !push_swap->a || !push_swap->a->next)
		return ;
	tmp_value = push_swap->a->value;
	tmp_index = push_swap->a->index;
	push_swap->a->value = push_swap->a->next->value;
	push_swap->a->index = push_swap->a->next->index;
	push_swap->a->next->value = tmp_value;
	push_swap->a->next->index = tmp_index;
	push_swap->operations[SA]++;
	handle_op(push_swap, "sa\n");
}

void	sb(t_stack *push_swap)
{
	int		tmp_value;
	int		tmp_index;

	if (!push_swap || !push_swap->b || !push_swap->b->next)
		return ;
	tmp_value = push_swap->b->value;
	tmp_index = push_swap->b->index;
	push_swap->b->value = push_swap->b->next->value;
	push_swap->b->index = push_swap->b->next->index;
	push_swap->b->next->value = tmp_value;
	push_swap->b->next->index = tmp_index;
	push_swap->operations[SB]++;
	handle_op(push_swap, "sb\n");
}

void	pa(t_stack *push_swap)
{
	t_list	*first;

	if (!push_swap || !push_swap->b)
		return ;
	first = push_swap->b;
	push_swap->b = push_swap->b->next;
	first->next = NULL;
	ft_lstadd_front(&push_swap->a, first);
	push_swap->operations[PA]++;
	handle_op(push_swap, "pa\n");
}

void	pb(t_stack *push_swap)
{
	t_list	*first;

	if (!push_swap || !push_swap->a)
		return ;
	first = push_swap->a;
	push_swap->a = push_swap->a->next;
	first->next = NULL;
	ft_lstadd_front(&push_swap->b, first);
	push_swap->operations[PB]++;
	handle_op(push_swap, "pb\n");
}
