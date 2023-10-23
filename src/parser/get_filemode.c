/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filemode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/23 19:45:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_filemode(t_token token)
{
	if (token == tk_dblgrt)
		return (O_APPEND);
	else if (token == tk_grt)
		return (O_RDWR);
	else if (token == tk_less)
		return (O_RDONLY);
	else if (token == tk_dblless)
		return (O_HEREDOC);
	return (EXITED);
}
