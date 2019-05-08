/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:45:36 by aben-azz          #+#    #+#             */
/*   Updated: 2019/05/08 07:36:36 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	add_cmd_to_history(char *string)
{
	if (g_shell->history->len)
		if (!ft_strcmp(string, g_shell->history->data[g_shell->history->len - 1]))
			return (1);
	if (!(g_shell->history->data[g_shell->history->len++] = ft_strdup(string)))
		return (0);
	g_shell->history->data[g_shell->history->len] = NULL;
	if (!write_history(string))
		return (-1);
	return (1);
}

int	debug_history(void)
{
	int i;

	i = 0;
	ft_printf("Len of history: %d;\n", g_shell->history->len);
	while (g_shell->history->data[i])
	{
		ft_printf("[%d]:  '%s';\n", i, g_shell->history->data[i]);
		i++;
	}
	return (1);
}

int	init_history(void)
{
	g_shell->history->len = 0;
	g_shell->history->data[0] = NULL;
	g_shell->history->read = 0;
	if (read_history() == -1)
		return (-1);
	return (1);
}

int	write_history(char *string)
{
	int fd;

	fd = open(HISTORY_FILE_NAME, O_RDWR | O_APPEND | O_CREAT, 0666);
	if (fd > 0)
	{
		//ft_dprintf(fd, "%s#", string);
		ft_putstr_fd(string, fd);
		ft_putchar_fd('#', fd);
		close(fd);
		return (1);
	}
	else
	{
		ft_putstr("21sh: History:  Error opening file\n");
	}
	return (-1);
}

int	read_history(void)
{
	char		*str;
	int			ret;
	int			fd;

	fd = open(HISTORY_FILE_NAME, O_RDWR | O_APPEND | O_CREAT, 0666);
	if (fd > 0)
	{
		while ((ret = get_next_line(fd, &str, '#')) > 0)
		{
			g_shell->history->read++;
			if (!(g_shell->history->data[g_shell->history->len++] = ft_strdup(str)))
				return (-1);
		}
	}
	close(fd);
	return (1);
}
