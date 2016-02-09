/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 16:47:25 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 16:47:25 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "defines_and_cie.h"
#include "serveur.h"
#include "tools.h"

int			create_server(int port)
{
	t_protoent		*proto;
	int				sock;
	t_sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
	{
		write(2, "Error with getprotobyname.\n",
			sizeof("Error with getprotobyname.\n"));
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const t_sockaddr *)&sin, sizeof(sin)) == -1)
	{
		write(2, "Bind failed.\n", sizeof("Bind failed.\n"));
		exit(-1);
	}
	listen(sock, 10);
	return (sock);
}

void		multi_client(int sock)
{
	int					quit;
	int					cs;
	t_sockaddr_in		csin;
	unsigned int		cslen;
	pid_t				pid;

	cs = accept(sock, (t_sockaddr *)&csin, &cslen);
	write(1, "A CLIENT HAS JOINED.\n", sizeof("A CLIENT HAS JOINED.\n"));
	pid = fork();
	if (pid == -1)
	{
		write(2, "FORK FAILED.\n", sizeof("FORK FAILED.\n"));
		exit(-1);
	}
	if (pid > 0)
		multi_client(sock);
	else
	{
		quit = 0;
		while (!quit)
			quit = loop_command(cs);
		close(cs);
		write(1, "A CLIENT HAS LEFT.\n", sizeof("A CLIENT HAS LEFT.\n"));
		exit(1);
	}
}

int			main(int ac, char **av)
{
	int					port;
	int					sock;

	if (ac == 2)
	{
		port = ft_atoi(av[1]);
		sock = create_server(port);
		multi_client(sock);
		close(sock);
	}
	else
		write(2, "You need to set a port.\n",
			sizeof("You need to set a port.\n"));
	return (0);
}
