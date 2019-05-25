/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 06:02:13 by aben-azz          #+#    #+#             */
/*   Updated: 2019/05/25 05:31:02 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		init_autocomp(int *count, t_ab *autocomp, char **string)
{
	int max_offset;

	(void)count;
	max_offset = 23;
	autocomp->row = g_shell->tcap->cursx_max / (max(max_offset + 2, 1));
	autocomp->len = ft_split_count(string);
	autocomp->col = autocomp->len / max(autocomp->row, 1);
	autocomp->carry = autocomp->len % max(autocomp->row, 1);
	return (max_offset);
}

int		print_name(t_ab *autocomp, char *string, int i, int max_offset)
{
	if (i == autocomp->pos)
		ft_putstr("\x1b[7m");
	ft_putstr(string);
	ft_putstr("\x1b[0m");
	ft_move(g_shell->tcap, "!right", max_offset - ft_strlen(string) + 2);
	return (1);
}

int		ft_tab(t_cap *tcap, t_ab *autocomp)
{
	(void)tcap;
	char *string[] = {"oui", "jsp", "gros", "delire", "jpp de ouf",
		"ta kiff", "xdd","ta kiffer ou quoi negro", "jm la vi", "jm la mort", NULL};
	int max_offset;
	int len;
	int count;
	int row;
	int col;
	int i;

	i = 0;
	col = 0;
	(void)len;
	max_offset = init_autocomp(&count, autocomp, string);
	tputs(tcap->down, 1, ft_put_termcaps);
	while (col < autocomp->col)
	{
		row = 0;
		while (row < autocomp->row)
		{
			print_name(autocomp, string[i], i, max_offset);
			i++;
			row++;
		}
		ft_move(tcap, "down", 1);
		col++;
	}
	if (autocomp->carry > 0)
	{
		row = autocomp->carry;
		while (row--)
			print_name(autocomp, string[i], i, max_offset) && i++;
	}
	dprintf(debug(), "carry: %d, %d\n", autocomp->carry, autocomp->col);
	ft_replace_cursor(tcap);
	ft_move(tcap, "up", autocomp->col + (autocomp->carry > 0 ? 1 : +1));
	return (1);
}