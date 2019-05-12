/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:04:00 by aben-azz          #+#    #+#             */
/*   Updated: 2019/05/12 02:09:13 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		arrow_up_event(t_cap *tcap)
{
	return (ft_up(tcap));
}

int		arrow_down_event(t_cap *tcap)
{
	return (ft_down(tcap));
}

int		arrow_right_event(t_cap *tcap)
{
	return (ft_right(tcap));
}

int		arrow_left_event(t_cap *tcap)
{
	return (ft_left(tcap));
}