/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 14:16:30 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/26 14:16:31 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	int		inc;

	n_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	inc = 0;
	while (*s1)
	{
		n_str[inc] = *s1;
		s1++;
		inc++;
	}
	while (*s2)
	{
		n_str[inc] = *s2;
		s2++;
		inc++;
	}
	n_str[inc] = 0;
	return (n_str);
}

char		*strjoin_add_slash(char *s1, char *s2)
{
	char	*n_str;
	int		inc;

	n_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	inc = 0;
	while (*s1)
	{
		n_str[inc] = *s1;
		s1++;
		inc++;
	}
	n_str[inc] = '/';
	inc++;
	while (*s2)
	{
		n_str[inc] = *s2;
		s2++;
		inc++;
	}
	n_str[inc] = 0;
	return (n_str);
}
