/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 14:41:29 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/26 14:41:30 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>

#include "defines_and_cie.h"
#include "serveur.h"
#include "tools.h"

int			have_path_and_is_file(char *path, char *buffer, int cs)
{
	t_stat	s;

	if (!buffer)
	{
		write(cs, "ERROR.\n", sizeof("ERROR.\n"));
		return (0);
	}
	stat(path, &s);
	if (!(s.st_mode & S_IFREG))
	{
		write(cs, "ERROR.\n", sizeof("ERROR.\n"));
		return (0);
	}
	return (1);
}
