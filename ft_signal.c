/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 19:15:36 by pferry            #+#    #+#             */
/*   Updated: 2014/03/25 18:20:19 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_quit(int sigint)
{
	sigint = sigint;
	ft_envreset(0);
}

void			ft_signal_init(void)
{
	signal(SIGTSTP, &ft_quit);
	signal(SIGQUIT, &ft_quit);
	signal(SIGINT, &ft_quit);
	signal(SIGTERM, &ft_quit);
	signal(SIGHUP, &ft_quit);
	signal(SIGTTIN, &ft_quit);
}
