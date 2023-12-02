/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:35:31 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/02 20:24:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function joins two arguments if they are together after removing
	quots between them and deletes the second argument.	*/

static void	ft_check_args(t_part *tokens, int index)
{
	t_part	*new;
	t_part	*temp;
	
	new = tokens;
	while (new->index != index)
		new = new->next;
	if (!new->next)
		return ;
	else
	{
		if (new->token == tk_arg && new->next->token == tk_arg)
		{
			temp = new->next;
			new->end = new->next->end;
			new->next = new->next->next;
			free (temp);
			if (new->next)
			{
				while (new->next)
				{
					new = new->next;
					new->index = new->index - 1;
				}
			}
				
		}
			
	}
	return ;	
}

/*	This function avoids double quotation marks which makes no sense,
	combination of simple & double quots with nothing inside.	*/
	
static int	ft_avoid_dblquot(t_global *global, t_part *tokens)
{
	int	status;
	t_part	*temp;

	status = 0;
	temp = tokens;
	while (temp->next->next->next->next)
	{
		if ((temp->next->token == tk_sglquot || temp->next->token == tk_dblquot)
			&& (temp->next->next->token == tk_sglquot
			|| temp->next->next->token == tk_dblquot)
			&& (temp->next->next->next->token == tk_sglquot
			|| temp->next->next->next->token == tk_dblquot)
			&& (temp->next->next->next->next->token == tk_sglquot
			|| temp->next->next->next->next->token == tk_dblquot))
		{
			status = ft_del_tkn(global, tokens, temp->index + 1);
			status = ft_del_tkn(global, tokens, temp->index + 1);
			status = ft_del_tkn(global, tokens, temp->index + 1);
			status = ft_del_tkn(global, tokens, temp->index + 1);
			ft_check_args(tokens, temp->index);
		}
		temp = temp->next;
	}
	return (status);
}

static int	ft_avoid_sglquot(t_global *global, t_part *tokens)
{
	int		status;
	t_part	*temp;

	status = 0;
	temp = tokens;
	while (temp->next->next)
	{
		if (temp->next->token == tk_sglquot
			&& temp->next->next->token == tk_sglquot)
		{
			status += ft_del_tkn(global, tokens, temp->index + 1);
			status += ft_del_tkn(global, tokens, temp->index + 1);
			ft_check_args(tokens, temp->index);
		}
		else if (temp->next->token == tk_dblquot
			&& temp->next->next->token == tk_dblquot)
		{
			status += ft_del_tkn(global, tokens, temp->index + 1);
			status += ft_del_tkn(global, tokens, temp->index + 1);
			ft_check_args(tokens, temp->index);
		}
		if (temp->next)
			temp = temp->next;
	}
	return (status);
}

/*	This function avoids quotation marks which makes no sense, it means 
	quotation marks with nothing inside.	*/

t_part	*ft_avoid_quot(t_global *global, t_part *tokens)
{
	int	status;

	status = 1;
	while (status != 0)
	{
		status = 0;
		if (tokens->next)
		{
			if (tokens->next->next)
			{
				status += ft_avoid_sglquot(global, tokens);
				if (tokens->next->next->next)
				{
					if (tokens->next->next->next->next)
						status = ft_avoid_dblquot(global, tokens);
				}
			}
		}
	}
	return (tokens);
}

static int	ft_avoid_sglquot(t_global *global)
{
	int		i;
	int		cut;
	char	*newline;

	i = 0;
	while (global->line[i])
	{
		if (global->line[i] == '\'')
		{
			cut = i - 1;
			i++;
			while (global->line[i] == '\"')
				i++;
			if (global->line[i] == '\'')
			{
				newline = ft_strjoin(ft_substr(newline, 0, cut), 
					ft_substr(global->line, i + 1, INT32_MAX));
				ft_strlcpy(global->line, newline, ft_strlen(newline) + 1);
				free(newline);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_avoid_dblquot(t_global *global)
{
	int		i;
	int		cut;
	char	*newline;

	i = 0;
	while (global->line[i])
	{
		if (global->line[i] == '\"')
		{
			cut = i - 1;
			i++;
			while (global->line[i] == '\'')
				i++;
			if (global->line[i] == '\"')
			{
				newline = ft_strjoin(ft_substr(newline, 0, cut), 
					ft_substr(global->line, i + 1, INT32_MAX));
				ft_strlcpy(global->line, newline, ft_strlen(newline) + 1);
				free(newline);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_avoid_quots(t_global *global)
{
	int	status;

	status = 1;
	while (status)
	{
		status = 0;
		status = status + ft_avoid_dblquot(global);
		status = status + ft_avoid_sglquot(global);
	}
	return ;	
}
	
	