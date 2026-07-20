/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:45:58 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/20 17:23:59 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_arrlen(char	**arr)
{
	size_t	len;

	len = 0;
	while (arr && arr[len])
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

static size_t	int_len(int n)
{
	size_t	len;
	long	nb;

	len = 0;
	if (n == 0)
		return (1);
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		++len;
	}
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*str;

	len = int_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
