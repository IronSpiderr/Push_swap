/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:13:53 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/25 11:47:42 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max_size(int **error)
{
	**error = 1;
	return (0);
}

static int	ft_sign(const char **str, int *i)
{
	int	sign;

	sign = 1;
	if (str[0][*i] == '+' || str[0][*i] == '-')
	{
		if (str[0][*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str, int *error)
{
	long long	nb;
	long		sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	*error = 0;
	if (!str)
		*error = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = ft_sign(&str, &i);
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb * sign < INT_MIN || nb * sign > INT_MAX)
			return (max_size(&error));
	}
	if (str[i])
		*error = 1;
	return ((int)(nb * sign));
}
