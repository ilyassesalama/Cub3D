/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalama <isalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:19:39 by isalama           #+#    #+#             */
/*   Updated: 2023/10/23 21:34:07 by isalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	process_result(char *str, int sign, int position)
{
	unsigned long	result;

	result = 0;
	if (!str)
		return (0);
	while (ft_isdigit(str[position]))
	{
		result *= 10;
		result += (str[position] - '0');
		position++;
	}
	return (result * sign);
}

bool	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	has_sign(char str)
{
	if (str)
		return (str == '-' || str == '+');
	return (false);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (has_sign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (process_result((char *)str, sign, i));
}
