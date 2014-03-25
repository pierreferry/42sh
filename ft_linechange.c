/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linechange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:07:14 by pferry            #+#    #+#             */
/*   Updated: 2014/03/24 15:36:00 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"

t_list	*lst;


static void	ft_linedel(char *str)
{
	sleep(2);
	str = str;
//	tputs(tgetstr("ei", NULL), 1, tputs_char);
	tputs(tgetstr("ch", NULL), 1, tputs_char);
//	tputs(tgetstr("im", NULL), 1, tputs_char);
//	tputs(tgetstr("nd", NULL), 1, tputs_char);
//	tputs(tgetstr("nd", NULL), 1, tputs_char);
	sleep(2);
	tputs(tgetstr("ce", NULL), 1, tputs_char);
}

/*
static int	ft_lstlen(t_list *lst)
{
	int		n;
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

*/

char	*ft_linechange(char *buff, size_t len, char *line)
{
	char			*new;
	static int		i;

	i = 0;
	new = ft_strnew(1);
	if (!lst)
	{
		ft_putstr("aieaiei");
		lst = NULL;
	}
	if (line == NULL)
	{
		if (*(int *)buff == UP && lst)
		{
			if (lst->next && lst->prev)
			{
				lst = lst->next;
				ft_linedel(lst->content);
				ft_putstr(lst->content);
				i++;
			}
			else if (lst && !(lst->prev))
			{
				ft_linedel(lst->content);
				ft_putstr(lst->content);
				if (lst->next)
					lst = lst->next;
			}
		}
		else if (*(int *)buff == DOWN && lst && i > 0)
		{
			lst = lst->prev;
			if (lst)
			{
				ft_linedel(lst->content);
				ft_putstr(lst->content);
			}
			i--;
		}
	}
	else if (line[0] != '\0')
	{
		i = 0;
		while (lst && lst->prev)
			lst = lst->prev;
		ft_putstr("oups");
		ft_lstadd(&lst, ft_lstnew(line, len));
	}
	return (new);
}
