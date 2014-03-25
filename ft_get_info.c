/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:58:11 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:17:36 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_get_info(char *file, int ret, int i)
{
	struct stat		buf;
	char			**s_path;
	char			*path;
	char			*tmp;

	s_path = ft_strsplit(file, '/');
	if (file[0] == '/')
		path = ft_strjoin("/", s_path[0]);
	else
		path = s_path[0];
	tmp = ft_strnew(0);
	while (s_path[i])
	{
		if (!(ret = lstat(path, &buf))
			&& !(buf.st_mode & (S_IWUSR | S_IWGRP | S_IWOTH)))
			ft_putendl_fd(": permission denied", 2);
		else if (ret)
		{
			ft_putstr_fd(s_path[i], 2);
			ft_putendl_fd(": no such file or directory", 2);
		}
		tmp = ft_strjoin(path, "/");
		free(path);
		path = (s_path[i + 1]) ? ft_strjoin(tmp, s_path[++i]) : s_path[++i];
		free(tmp);
	}
}
