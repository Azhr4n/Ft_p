/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 16:49:48 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 16:49:48 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

int			have_path_and_is_file(char *path, char *buffer, int cs);
int			open_stream(char *s1, char *s2, int *fd, int *fd2);
int			exec_get_file(char **tab, int cs);
int			exec_put_file(char **tab, int cs);
int			create_server(int port);
int			loop_command(int cs);

void		exec_ls(char **tab, int cs);
void		exec_pwd(char **tab, int cs);
void		close_and_free(int fd, int fd2, char *path);

#endif
