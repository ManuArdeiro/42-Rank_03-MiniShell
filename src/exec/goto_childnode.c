/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_childnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/26 20:42:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_goto_childnode(t_minitree *root, t_bool childnode, t_global *global)
{
	if (root == NULL)
		return ;
	if (childnode == LEFT && ft_is_emptynode(root->leftchild) == FALSE)
	{
		ft_executecommand(
			(t_command *)((t_mininode *)
				root->leftchild->content)->content, global);
	}
	else if (childnode == RIGHT && ft_is_emptynode(root->rightchild) == FALSE)
	{
		ft_executecommand(
			(t_command *)((t_mininode *)
				root->rightchild->content)->content, global);
	}
}
