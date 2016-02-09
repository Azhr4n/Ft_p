/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 20:00:25 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/24 20:00:26 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "defines_and_cie.h"
#include "serveur.h"
#include "tools.h"

int			exec_get_file(char **tab, int cs)
{
	char	buffer[BUFFSIZE + 1];
	char	*path;
	int		ret;
	int		fd2;
	int		fd;

	ret = read(cs, buffer, BUFFSIZE);
	buffer[ret] = 0;
	path = strjoin_add_slash(buffer, tab[1]);
	if (!have_path_and_is_file(tab[1], buffer, cs))
		return (-1);
	if (!open_stream(tab[1], path, &fd, &fd2))
	{
		write(cs, "ERROR.\n", sizeof("ERROR.\n"));
		return (-1);
	}
	ret = 1;
	while ((ret = read(fd, buffer, BUFFSIZE)) > 0)
	{
		buffer[ret] = 0;
		write(fd2, buffer, ret);
	}
	write(cs, "SUCCESS.\n", sizeof("SUCCESS.\n"));
	close_and_free(fd, fd2, path);
	return (0);
}

int			exec_put_file(char **tab, int cs)
{
	char	buffer[BUFFSIZE + 1];
	char	*path;
	int		ret;
	int		fd2;
	int		fd;

	ret = read(cs, buffer, BUFFSIZE);
	buffer[ret] = 0;
	path = strjoin_add_slash(buffer, tab[1]);
	if (!have_path_and_is_file(path, buffer, cs))
		return (-1);
	if (!open_stream(path, tab[1], &fd, &fd2))
	{
		write(cs, "ERROR.\n", sizeof("ERROR.\n"));
		return (-1);
	}
	ret = 1;
	while ((ret = read(fd, buffer, BUFFSIZE)) > 0)
	{
		buffer[ret] = 0;
		write(fd2, buffer, ret);
	}
	write(cs, "SUCCESS.\n", sizeof("SUCCESS.\n"));
	close_and_free(fd, fd2, path);
	return (0);
}

void		exec_ls(char **tab, int cs)
{
	int			status;
	t_rusage	usage;
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		write(2, "FORK FAILED.\n", sizeof("FORK FAILED.\n"));
		exit(-1);
	}
	if (pid > 0)
	{
		wait4(pid, &status, 0, &usage);
		write(cs, "SUCCESS.\n", sizeof("SUCCESS.\n"));
	}
	else
	{
		dup2(cs, 1);
		dup2(cs, 2);
		close(cs);
		if ((execv("/bin/ls", tab)) == -1)
			exit(-1);
	}
}

void		exec_pwd(char **tab, int cs)
{
	int			status;
	t_rusage	usage;
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		write(2, "FORK FAILED.\n", sizeof("FORK FAILED.\n"));
		exit(-1);
	}
	if (pid > 0)
	{
		wait4(pid, &status, 0, &usage);
		write(cs, "SUCCESS.\n", sizeof("SUCCESS.\n"));
	}
	else
	{
		dup2(cs, 1);
		dup2(cs, 2);
		close(cs);
		if ((execv("/bin/pwd", tab)) == -1)
			exit(-1);
	}
}
