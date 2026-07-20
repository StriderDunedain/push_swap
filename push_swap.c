/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/20 18:04:02 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	ps;

	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	set_strategy(&ps);
	assign_ranks(ps.a);
	if (ps.required_algo == ALGO_SIMPLE)
		selection_sort(&ps);
	else if (ps.required_algo == ALGO_MEDIUM)
		chunk_sort(&ps);
	else if (ps.required_algo == ALGO_COMPLEX)
		radix_sort(&ps);
	if (ps.bench)
		get_benchmarks(&ps);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
