/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 13:28:06 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 20:37:26 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		ft_putstr("new");
		*alst = new;
	}
	else
	{
		(*alst)->prev = new;
		new->next = (*alst);
		*alst = new;
	}

}
