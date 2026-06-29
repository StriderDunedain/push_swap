/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:25:20 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/29 20:15:23 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parse_args.h"

static double	measure_disorder(t_list *stack)
{
	int		i;
	int		j;
	int		total_pairs;
	double	mistakes;
	size_t	lstsize;
	
	lstsize = ft_lstsize(stack);
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
			if (stack[i] > stack[j])  // TODO: Adjust to LL
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

static void	set_flags(char **argv, t_stack *algo, double disorder)
{
	algo->strategy = choose_adaptive_strategy(disorder);
	algo->bench = false;
	while (*argv)
	{
		if (ft_strcmp(*argv, BENCH_FLAG) == NO_DIFF)
			algo->bench = true;
		else if (ft_strcmp(*argv, SIMPLE_FLAG) == NO_DIFF)
			algo->strategy = SIMPLE_STRATEGY;
		else if (ft_strcmp(*argv, MEDIUM_FLAG) == NO_DIFF)
			algo->strategy = MEDIUM_STRATEGY;
		else if (ft_strcmp(*argv, COMPLEX_FLAG) == NO_DIFF)
			algo->strategy = COMPLEX_STRATEGY;
		else if (ft_strcmp(*argv, COMPLEX_FLAG) == NO_DIFF)
			algo->strategy = choose_adaptive_strategy(disorder);
		++argv;
	}
}

void	set_settings(char **argv, t_stack *algo)
{
	double	disorder;

	disorder = measure_disorder(algo->a);
	set_flags(argv, algo, disorder);
	algo->disorder = disorder;
}
