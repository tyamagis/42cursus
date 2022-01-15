/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:56:17 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/09 17:23:22 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*gnl_trim_store(char **str, char *nl, char **line);
char	*gnl_trim_line(char **str, char *nl);
char	*gnl_split(char **str, char *nl);
char	*read_buf(int fd, char **str, char **nl, char *buf);
char	*get_next_line(int fd);
size_t	gnl_strlen(char *str);
char	*gnl_strcat(char *str, char *buf, size_t buf_len);
char	*find_nl(char *str, char **nl);
void	*free_store(char **str);

#endif
