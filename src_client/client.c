/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:20:42 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 17:20:42 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "defines_and_cie.h"
#include "client.h"
#include "tools.h"

int			create_client(char *addr, int port)
{
	t_protoent		*proto;
	int				sock;
	t_sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
	{
		ft_putstr("Error with getprotobyname.\n", 2);
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const t_sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Connect failed.\n", 2);
		exit(-1);
	}
	return (sock);
}

void		read_from_server(int sock, char *buffer)
{
	int		ret;

	ret = BUFFSIZE;
	while (ret == BUFFSIZE)
	{
		ret = read(sock, buffer, BUFFSIZE);
		buffer[ret] = 0;
		ft_putstr(buffer, 1);
	}
}

static int	loop_command_2(char *buffer, char **tab, int sock)
{
	char	*path;

	if (!ft_strcmp("quit\n", buffer))
	{
		free_tab(tab);
		return (0);
	}
	else if (!ft_strcmp("ls", tab[0]) || !ft_strcmp("pwd", tab[0]))
	{
		read_from_server(sock, buffer);
		read_from_server(sock, buffer);
	}
	else if (!ft_strcmp("cd", tab[0]))
		read_from_server(sock, buffer);
	else if (!ft_strcmp("get", tab[0]) || !ft_strcmp("put", tab[0]))
	{
		if ((path = getcwd(buffer, BUFFSIZE)))
			write(sock, buffer, BUFFSIZE);
		else
			write(sock, "", 1);
		read_from_server(sock, buffer);
	}
	else
		read_from_server(sock, buffer);
	return (1);
}

int			loop_command(int sock)
{
	char	buffer[BUFFSIZE + 1];
	char	**tab;
	int		ret;

	write(1, "Client -> ", sizeof("Client -> "));
	ret = read(0, buffer, BUFFSIZE);
	buffer[ret] = '\0';
	write(sock, buffer, BUFFSIZE);
	tab = ft_split(buffer);
	if (!loop_command_2(buffer, tab, sock))
		return (1);
	free_tab(tab);
	return (0);
}

int			main(int ac, char **av)
{
	int		quit;
	int		port;
	int		sock;

	if (ac == 3)
	{
		port = ft_atoi(av[2]);
		sock = create_client(av[1], port);
		quit = 0;
		while (!quit)
			quit = loop_command(sock);
		close(sock);
	}
	else
		ft_putstr("You need to set a port.\n", 2);
	return (0);
}
