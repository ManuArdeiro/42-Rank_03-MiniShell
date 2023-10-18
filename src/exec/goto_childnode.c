/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_childnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/18 18:10:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_goto_childnode(
		t_minitree *root, char **envp, t_bool childnode, t_global *global)
{
	int	status;

	status = EXIT_SUCCESS;
	if (root == NULL)
		return (EXITED);
	if (childnode == LEFT && ft_is_emptynode(root) == FALSE)
	{
		status
			= ft_executecommand(
				(t_command *)((t_mininode *)
					root->leftchild->content)->content, envp, global);
	}
	else if (childnode == RIGHT && ft_is_emptynode(root) == FALSE)
	{
		status
			= ft_executecommand(
				(t_command *)((t_mininode *)
					root->rightchild->content)->content, envp, global);
	}
	return (status);
}
