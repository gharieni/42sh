/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlechien <tlechien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:57:28 by tlechien          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/05/20 13:04:06 by tlechien         ###   ########.fr       */
=======
/*   Updated: 2019/06/04 22:20:46 by tlechien         ###   ########.fr       */
>>>>>>> tlechien
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** Builtin that resumes interruped processus.
**  Needs protection on already finished process ??
*/

static	int	bg_all(void)
{
	t_child	**node;

	node = NULL;
	search_status(node, S_SUSP);
	if (node)
		return (bg_resume(node));
<<<<<<< HEAD
	ft_putendl("bg: no current job\n");
	return (1);
}

int			bg_builtin(char **cmd)
=======
	err_display("bg: no current job\n", NULL, NULL);
	return (1);
}

int			bg_builtin(int ac, char **cmd)
>>>>>>> tlechien
{
	t_child	**node;
	int		i;
	int		ret;

<<<<<<< HEAD
=======
	(void)ac;
>>>>>>> tlechien
	ret = 0;
	node = NULL;
	if ((i = 1) && cmd[0] && !cmd[1])
		return (bg_all());
	while (cmd[i] && *cmd[i] == '%')
	{
		if (search_pid(node, ++cmd[i], 0) && search_process(node, cmd[i])
			&& search_index(node, cmd[i]))
			break ;
		if ((ret = bg_resume(node)))
			break ;
		i++;
	}
	if (!node && (ret = 1))
<<<<<<< HEAD
		ft_printf("bg: %s: no such job\n", cmd[i]);
	else if (ret)
		ft_printf("bg: job already in background");
=======
		err_display("bg: ", cmd[i],": no such job\n");
	else if (ret)
		err_display("bg: job already in background", NULL, NULL);
>>>>>>> tlechien
	return (ret);
}

int			bg_resume(t_child **node)
{
	if (!node || (*node)->status != S_SUSP || kill((*node)->pid, SIGCONT))
		return (1);
	(*node)->priority = 0;
	(*node)->status = S_RUN;
	return (0);
}
