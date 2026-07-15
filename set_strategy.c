/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:25:20 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/15 20:10:35 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	measure_disorder(t_stack *push_swap)
{
	int		i;
	int		j;
	int		total_pairs;
	double	mistakes;
	size_t	lstsize;

	lstsize = ft_lstsize(push_swap->a);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	if (lstsize <= 1)
		return (0.0);
	while (i < lstsize)
	{
		j = i + 1;
		while (j < lstsize)
		{
			if (stack[i] > stack[j]) // TODO: Adjust to LL
				++mistakes;
			++total_pairs;
			++j;
		}
		++i;
	}
	return (mistakes / total_pairs);
}

static char	*choose_adaptive_strategy(double disorder)
{
	if (disorder < DISORDER_SIMPLE)
		return (SIMPLE_STRATEGY);
	else if (disorder < DISORDER_MEDIUM)
		return (MEDIUM_STRATEGY);
	return (COMPLEX_STRATEGY);
}

void	set_strategy(t_stack *push_swap)
{
	double	disorder;

	disorder = measure_disorder(push_swap->a);
	push_swap->disorder = disorder;
	if (push_swap->required_algo == ALGO_SIMPLE)
		push_swap->strategy = SIMPLE_STRATEGY;
	else if (push_swap->required_algo == ALGO_MEDIUM)
		push_swap->strategy = MEDIUM_STRATEGY;
	else if (push_swap->required_algo == ALGO_COMPLEX)
		push_swap->strategy = COMPLEX_STRATEGY;
	else
		push_swap->strategy = choose_adaptive_strategy(disorder);
}
