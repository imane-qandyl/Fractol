/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:01:17 by imqandyl          #+#    #+#             */
/*   Updated: 2025/01/24 17:46:38 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	str_compare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	power(int base, unsigned int pow)
{
	double	res;

	res = 1;
	while (pow != 0)
	{
		res = res * base;
		pow--;
	}
	return (res);
}

double	str_to_double(const char *str)
{
	double			res;
	double			sign;
	unsigned int	i;
	unsigned int	j;

	res = 0;
	i = 0;
	sign = 1.0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1.0;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	j = 1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res + (str[i++] - '0') / power(10.0, j++);
	return (res * sign);
}

int	validate_number(const char *str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			i++;
		if ((str[i] < '0' || str[i] > '9'))
			flag = 0;
		i++;
	}
	return (flag);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
