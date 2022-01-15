/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:15:47 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/27 12:23:05 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct	s_ls
{
	char			*fname;
	unsigned long	mtime;
	unsigned long	nsec;
}				t_ls;

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

void	db(char *str)
{
	printf("\n-----\n!! check !!\n-----\n\n");
	printf("%s\n", str);
	printf("\n-----\n!! check !!\n-----\n\n");
}

void	add_ls(t_ls ls, struct dirent *dir, struct stat *buf)
{
	db("at the start of func named add_ls");
	ls.fname = ft_strdup(dir->d_name);
//	ls.fname = dir->d_name;
	ls.mtime = buf->st_mtimespec.tv_sec;
	ls.nsec = buf->st_mtimespec.tv_nsec;
}

int		main(int ac, char *av[])
{
	DIR				*dp;
	struct dirent	*dir;
	struct stat		buf;
	size_t			num_f;
	t_ls			*t_flist;
	int				i;

	if (ac > 1)
	{
		perror("Err: too many args");
		return (1);
	}
	if (!(dp = opendir(".")))
	{
		perror("Err: opendir");
		return (1);
	}
	num_f = 0;
	while ((dir = readdir(dp)))
	{
		if (*(dir->d_name) != '.')
		{
			printf("dir->d_namlen : %hu\n", dir->d_namlen);
			printf("dir->d_name : %s\n", dir->d_name);
			write(1, dir->d_name, dir->d_namlen);
			printf("\n-------\n");
			num_f++;
		}
	}
	if (!(dp = opendir(".")))
	{
		perror("Err: opendir");
		return (1);
	}
	if(!(t_flist = (t_ls *)malloc((sizeof(t_ls) * num_f) + 1)))
	{
		perror("Err: malloc");
		return (1);
	}
	i = 0;
	while ((dir = readdir(dp)))
	{
		db("line:88 into while loop");
		lstat(dir->d_name, &buf);
		add_ls(t_flist[i], dir, &buf);
		/* printf ------------------------- */
		printf("t_flist[%d]->fname : %s\n", i, t_flist[i].fname);
		printf("t_flist[%d]->mtime : %lu\n", i, t_flist[i].mtime);
		printf("t_flist[%d]->nsec : %lu\n", i, t_flist[i].nsec);
		i++;
	}
	closedir(dp);
	return (0);
}
