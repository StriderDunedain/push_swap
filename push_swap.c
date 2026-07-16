/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 11:45:53 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <string.h>


static void	printlist(t_list *tmp)
{
	if (!tmp)
		return ;
	while (1)
	{
		printf("%d, %d\n", tmp->value, tmp->index);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

void	handle_op(t_stack *push_swap, char *op_name)
{
	if (push_swap->presort)
		ft_printf(STDOUT_FILENO, op_name);
}

int	parse_args(int argc, char **argv, t_stack *push_swap)
{
	if (!fill_stack(argc, argv, push_swap))
		return (1);
	set_strategy(push_swap);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	push_swap;

	memset(&push_swap, 0, sizeof(t_stack));
	parse_args(argc, argv, &push_swap);
	rrb(&push_swap);
	sb(&push_swap);
	pa(&push_swap);
	printf("strategy: %s\n", push_swap.strategy);
	printf("bench: %i\n", push_swap.bench);
	printf("push_swap.a:\n");
	printlist(push_swap.a);
	printf("push_swap.b:\n");
	printlist(push_swap.b);
	ft_lstclear(&push_swap.a);
	ft_lstclear(&push_swap.b);
	return (0);
}
