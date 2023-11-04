/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_emptynode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 20:06:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_emptynode(t_minitree *root)
{
	if (root == NULL || root->content == NULL
		|| ((t_mininode *)root->content)->content == NULL)
		return (TRUE);
	return (FALSE);
}
