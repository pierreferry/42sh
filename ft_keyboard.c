/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 13:13:16 by pferry            #+#    #+#             */
/*   Updated: 2014/03/25 19:13:19 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


static void		ft_printline(char *line, int i)
{
	int		len;

	len = ft_strlen(line);
	while (len > i)
	{
		tputs(tgetstr("nd", NULL), 1, tputs_char);
		len--;
	}
	len = ft_strlen(line);
	while (len > 1)
	{
		tputs(tgetstr("dc", NULL), 1, tputs_char);
		ft_putchar('\b');
		len--;
	}
	tputs(tgetstr("dc", NULL), 1, tputs_char);
	len = ft_strlen(line);
	ft_putstr(line);
	while (len > i)
	{
		tputs(tgetstr("le", NULL), 1, tputs_char);
		len--;
	}
}

static char		*ft_cut_paste(char **line, size_t i)
{
	char	*new;
	int		n;

	n = 0;
	new = ft_strnew(1);
	while (i < ft_strlen(*line))
	{
		new = ft_charjoin(new, (*line)[i], n++);
		*line = ft_chardelete(*line, i + 1);
		tputs(tgetstr("dc", NULL), 1, tputs_char);
	}
	return (new);
}

char			*ft_keyboard(void)
{
	char	buff[5];
	char	*line;
	char	*save;
	size_t	i;

	i = 0;
	if (!(line = ft_strnew(1)))
		ft_error("malloc.");
	while (42)
	{
		ft_bzero(buff, 5);
		read(0, buff, 5);
		if (buff[0] == '\n')
			return (ft_strtrim(line));
		if (*(int *)buff > 31 && *(int *)buff < 127)
		{
			line = ft_charjoin(line, buff[0], i);
			i++;
			ft_printline(line, i);
		}
		else if (*(int *)buff == 9)
		{
			line = ft_charjoin(line, ' ', i);
			i++;
			ft_printline(line, i);
			line = ft_charjoin(line, ' ', i);
			i++;
			ft_printline(line, i);
			line = ft_charjoin(line, ' ', i);
			i++;
			ft_printline(line, i);
			line = ft_charjoin(line, ' ', i);
			i++;
			ft_printline(line, i);
		}
		else if (*(int *)buff == 127 && i > 0) //delete <-
		{
			line = ft_chardelete(line, i);
			ft_putchar('\b');
			tputs(tgetstr("dc", NULL), 1, tputs_char);
			i--;
		}
		else if (*(int *)buff == 2117294875 && i < ft_strlen(line)) //delete ->
		{
			line = ft_chardelete(line, i + 1);
			tputs(tgetstr("dc", NULL), 1, tputs_char);
		}
		else if (*(int *)buff == 4414235 && i < ft_strlen(line)) // RIGHT
		{
			tputs(tgetstr("nd", NULL), 1, tputs_char);
			i++;
		}
		else if (*(int *)buff == 4479771 && i > 0) // LEFT
		{
			tputs(tgetstr("le", NULL), 1, tputs_char);
			i--;
		}
		else if (*(int *)buff == 24 && i < ft_strlen(line))
		{
			save = ft_cut_paste(&line, i);
			save = save;
		}
//		else if (*(int *)buff == 16 && save)
//		{
//			tputs(tgetstr("im", NULL), 1, tputs_char);
//			ft_putstr(save);
//			tputs(tgetstr("ei", NULL), 1, tputs_char);
//			i += ft_strlen(save);
//		}
		else if (*(int *)buff == 1)
		{
			while (i > 0)
			{
				tputs(tgetstr("le", NULL), 1, tputs_char);
				i--;
			}
		}
		else if (*(int *)buff == 5)
		{
			while (i < ft_strlen(line))
			{
				tputs(tgetstr("nd", NULL), 1, tputs_char);
				i++;
			}
				
		}
//		else
		//		ft_putnbr(*(int *)buff);
	}
}
