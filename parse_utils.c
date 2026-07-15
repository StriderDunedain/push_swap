/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:45:58 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/15 19:51:01 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_len(char	**arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		++len;
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned int)*s1 - (unsigned int)*s2);
}

long	ft_atol(const char *str)
{
	int		sign;
	int		idx;
	long	res;

	idx = 0;
	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
		res = res * 10 + str[idx++] - '0';
	if (idx)
		return (sign * res);
	return (0);
}
