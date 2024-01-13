/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:26:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/13 12:01:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_terminal(void)
{
	t_termios	settings;
	int			desc;

	desc = 0;
	if (tcgetattr (desc, &settings) < 0)
		ft_printerror(__func__, "error in tcgetattr");
	settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr (desc, TCSANOW, &settings) < 0)
		ft_printerror(__func__, "error in tcsetattr");
}
