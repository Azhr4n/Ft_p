/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 16:01:08 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/26 16:01:09 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "serveur.h"

int			open_stream(char *s1, char *s2, int *fd, int *fd2)
{
	if ((*fd = open(s1, O_RDONLY)) == -1)
		return (0);
	if ((*fd2 = open(s2, O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) == -1)
	{
		close(*fd);
		return (0);
	}
	return (1);
}

void		close_and_free(int fd, int fd2, char *path)
{
	close(fd);
	close(fd2);
	free(path);
}
