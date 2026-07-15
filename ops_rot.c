/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:45 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/15 21:46:11 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *push_swap)
{
	t_list	*first;
	t_list	*last;

	if (!push_swap || !push_swap->a || !push_swap->a->next)
		return ;
	first = push_swap->a;
	push_swap->a = first->next;
	first->next = NULL;
	last = ft_lstlast(push_swap->a);
	last->next = first;
	push_swap->operations[RA]++;
	handle_op(push_swap, "ra\n");
}

void	rb(t_stack *push_swap)
{
	t_list	*first;
	t_list	*last;

	if (!push_swap || !push_swap->b || !push_swap->b->next)
		return ;
	first = push_swap->b;
	push_swap->b = first->next;
	first->next = NULL;
	last = ft_lstlast(push_swap->b);
	last->next = first;
	push_swap->operations[RB]++;
	handle_op(push_swap, "rb\n");
}

void	rra(t_stack *push_swap)
{
	t_list	*prev;
	t_list	*last;

	if (!push_swap || !push_swap->a || !push_swap->a->next)
		return ;
	prev = push_swap->a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = push_swap->a;
	push_swap->a = last;
	push_swap->operations[RRA]++;
	handle_op(push_swap, "rra\n");
}

void	rrb(t_stack *push_swap)
{
	t_list	*prev;
	t_list	*last;

	if (!push_swap || !push_swap->b || !push_swap->b->next)
		return ;
	prev = push_swap->b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = push_swap->b;
	push_swap->b = last;
	push_swap->operations[RRB]++;
	handle_op(push_swap, "rrb\n");
}
