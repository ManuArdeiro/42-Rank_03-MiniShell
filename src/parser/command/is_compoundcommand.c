/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_compoundcommand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:34:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/15 18:36:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_compoundcommand(t_nodetype nodetype)
{
	if (nodetype == n_and || nodetype == n_or || nodetype == n_subshell)
		return (TRUE);
	return (FALSE);
}
