/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearscreen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:58:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/13 20:05:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_clearscreen(t_list *envlist)
{
	char	buffer[BUFSIZ];
	char	*string;
	char	*term;

	string = NULL;
	term = ft_getenv("TERM", envlist);
	if (term != NULL)
	{
		tgetent(buffer, term);
		string = tgetstr("cl", NULL);
		fputs(string, stdout);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
