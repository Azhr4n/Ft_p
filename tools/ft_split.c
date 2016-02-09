/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:41:43 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/24 16:41:43 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

static int	nb_words(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i + 1])
	{
		if ((str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n')
			&& (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			nb++;
		i++;
	}
	if (!str[i + 1] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		nb++;
	return (nb);
}

static int	len_next_word(char *str)
{
	int		len;

	len = 0;
	while ((*str != ' ' || *str != '\t' || *str != '\n') && *str)
	{
		len++;
		str++;
	}
	return (len);
}

char		**ft_split(char *str)
{
	char	**tab;
	int		len;
	int		i;
	int		j;

	len = nb_words(str);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		while ((*str == ' ' || *str == '\t' || *str == '\n') && *str)
			str++;
		tab[i] = (char *)malloc(sizeof(char) * (len_next_word(str) + 1));
		j = 0;
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str)
		{
			tab[i][j] = *str;
			str++;
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
