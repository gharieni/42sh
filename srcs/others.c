/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:35:56 by aben-azz          #+#    #+#             */
/*   Updated: 2019/04/28 15:36:30 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_put_termcaps(int c)
{
	write(1, &c, 1);
	return (1);
}

void	display_prompt(void)
{
	ft_printf("\x1b[32m$21sh>\x1b[0m ");
}