/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 16:03:53 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/26 16:03:54 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "defines_and_cie.h"
#include "serveur.h"
#include "tools.h"

static int	if_forest(char **tab, int cs)
{
	if (!ft_strcmp("quit", tab[0]))
		return (0);
	if (!ft_strcmp("ls", tab[0]))
		exec_ls(tab, cs);
	else if (!ft_strcmp("pwd", tab[0]))
		exec_pwd(tab, cs);
	else if (!ft_strcmp("get", tab[0]))
		exec_get_file(tab, cs);
	else if (!ft_strcmp("put", tab[0]))
		exec_put_file(tab, cs);
	else if (!ft_strcmp("cd", tab[0]))
	{
		if (chdir(tab[1]) == -1)
			write(cs, "ERROR.\n", sizeof("ERROR.\n"));
		else
			write(cs, "SUCCESS.\n", sizeof("SUCCESS.\n"));
	}
	else
		write(cs, "ERROR.\n", sizeof("ERROR.\n"));
	return (1);
}

int			loop_command(int cs)
{
	char	buffer[BUFFSIZE + 1];
	char	**tab;
	int		ret;

	ret = read(cs, buffer, BUFFSIZE);
	buffer[ret] = '\0';
	tab = ft_split(buffer);
	if (!if_forest(tab, cs))
		return (1);
	free_tab(tab);
	return (0);
}
