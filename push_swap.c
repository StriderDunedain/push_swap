/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 23:22:14 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <string.h>

static void	printlist(t_list *lst)
{
	if (!lst)
		return ;
	while (1)
	{
		ft_printf(STDOUT_FILENO, "%d, %d\n", lst->value, lst->index);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
}

int	set_ps(t_stack *ps)
{
	ps->strategy = NULL;
	ps->disorder = 0;
	ps->a = NULL;
	ps->b = NULL;
	ps->total_ops = 0;
	ps->bench = false;
	ps->required_algo = ALGO_NONE;
}


int	main(int argc, char **argv)
{
	t_stack	ps;

	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	printlist(ps.a);
	printf("\n\n");
	set_strategy(&ps);
	printf("ra: %i", ps.required_algo);
	if (ps.required_algo == ALGO_SIMPLE)
		// simple_sort(&ps);  // TODO: Rename to actual sort
		;
	else if (ps.required_algo == ALGO_MEDIUM)
		printf("HERE!!!"), chunk_sort(&ps);
	else if (ps.required_algo == ALGO_COMPLEX)
		// complex_sort(&ps);  // TODO: Rename to actual sort
		;
	printlist(ps.a);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
