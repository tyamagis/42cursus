/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:20:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/08 18:22:47 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	gnl_strlen(char *s);
char	*gnl_split_rest(char **s, char *tmp[]);
char	*gnl_split_first(char **s, char *tmp[]);
char	*gnl_strcat(char *s1, char *s2, size_t buf_len);
char	*gnl_split(char **s, char *tmp[]);
char	*find_nl(char *s, char *tmp[]);
char	*read_buf(int fd, char **s, char *tmp[]);
char	*get_next_line(int fd);

#endif
