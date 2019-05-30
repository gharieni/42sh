/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 00:20:29 by aben-azz          #+#    #+#             */
/*   Updated: 2019/05/30 05:03:11 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		home_event(t_cap *tcap)
{
	tputs(tgoto(tgetstr("ch", NULL), UNUSED,
		tcap->prompt_len + 1), 1, ft_put_termcaps);
	return (1);
}

int		end_event(t_cap *tcap)
{
	(void)tcap;
	;
	return (1);
}
