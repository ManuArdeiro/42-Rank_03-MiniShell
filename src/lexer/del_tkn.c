/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tkn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:47:44 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/02 20:05:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_subline (t_global *global, t_part *tokens, int index)
{
	char	*newline;
	t_part	*new;

	if (index <= 0 || !global) 
		return ;
	new = tokens;
	while (new->next && new->index < index)
		new = new->next;
	newline = ft_substr(global->line, 0, new->start);
	newline = ft_strjoin(newline, ft_substr(global->line, new->start + 1, new->end));
	ft_strlcpy(global->line, newline, ft_strlen(newline) + 1);
printf("newline = %s\n", global->line);
	free(newline);
	return ;
}

int	ft_del_tkn(t_global *global, t_part *tokens, int index)
{
	t_part	*new;
	t_part	*temp;

	if (!tokens || !index)
		return (EXIT_SUCCESS);
	new = tokens;
	while (new->index != (index - 1))
		new = new->next;
	temp = new->next->next;
	if (!temp)
		return (EXIT_SUCCESS);
	free(new->next);
	new->next = temp;
	ft_subline(global, tokens, index);
	while (new->next)
	{
		new = new->next;
		new->index = new->index - 1;
		new->start = new->start - 1;
		new->end = new->end - 1;
	}
	return (EXIT_FAILURE);
}