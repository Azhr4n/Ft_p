/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:07:59 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 17:07:59 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	get_mul(char *str)
{
	int		mul;

	mul = 0;
	while (*str)
	{
		if (!mul)
			mul = 1;
		else
			mul *= 10;
		str++;
	}
	return (mul);
}

int			ft_atoi(char *str)
{
	int		result;
	char	*tmp;
	int		mul;
	int		i;

	tmp = str;
	if (*str == '-' || *str == '+')
		str++;
	i = 0;
	result = i;
	mul = get_mul(str);
	while (str[i])
	{
		result += (str[i] - '0') * mul;
		mul /= 10;
		i++;
	}
	if (*tmp == '-')
		return (-result);
	return (result);
}

void		ft_putstr(char *str, int output)
{
	while (*str)
	{
		write(output, str, 1);
		str++;
	}
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
