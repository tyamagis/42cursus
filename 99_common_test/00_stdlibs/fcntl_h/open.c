/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:48:28 by tyamagis          #+#    #+#             */
/*   Updated: 2021/02/15 23:15:25 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fcntl.h / open() function test c file.
** - - - - -
**  - PROTOTYPE -
** int open(const char *path, int oflag, ...);
** - RETURN VALUE -
** Success --> non-negative int termed a fd.
** Fail --> return -1 and set errno.
** - OFLAGS (a part of)
** #define O_RDONLY		0 : read only
** #define O_WRONLY		1 : write only
** #define O_RDWR		2 : read and write only
** #define O_ACCMODE	3 : mask for above modes (??
*/

#include <fcntl.h>

int main(){
	int fd = open(/* char *path, int oflag */);
	// read();
	// write(); // or other func to use opened file.
	// close();
	return (0);
}
