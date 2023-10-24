/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/24 20:17:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_printlist(t_list *list)
{
	t_list	*node;
	int		count;

	count = 0;
	if (list == NULL)
	{
		printf("%s\n", NULL);
		return ;
	}
	node = list;
	while (node != NULL)
	{
		printf("File[%d] -> %s -> mode = %d\n",
			count,
			((t_file *)(node->content))->name,
			((t_file *)(node->content))->mode);
		count++;
		node = node->next;
	}
}

static void	ft_print_stringarray(char **strarray)
{
	int		count;

	if (strarray == NULL)
	{
		printf("%s\n", NULL);
		return ;
	}
	count = 0;
	while (strarray[count] != NULL)
	{
		printf("argument[%d] -> %s\n", count, strarray[count]);
		count++;
	}
}

void	ft_printcommand(t_command *command)
{
	int	count;

	count = 0;
	if (command == NULL)
		return ;
	printf("****** Command ********\n\n"
		"name = %s\n", command->name);
	ft_print_stringarray(command->args);
	printf("-----------------------------\n"
		"****** Input files ********\n\n");
	ft_printlist(command->infile);
	printf("-----------------------------\n"
		"****** output files ********\n\n");
	ft_printlist(command->outfile);
	printf("-----------------------------\n");
}
