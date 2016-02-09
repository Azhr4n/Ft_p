/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:13:42 by pivanovi          #+#    #+#             */
/*   Updated: 2014/10/22 17:13:43 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);

char		**ft_split(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*strjoin_add_slash(char *s1, char *s2);

void		free_tab(char **tab);
void		ft_putstr(char *str, int output);

#endif
