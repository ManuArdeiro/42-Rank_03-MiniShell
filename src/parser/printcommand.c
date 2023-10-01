/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/01 16:08:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printcommand(t_command *command)
{
	int	count;

	count = 0;
	if (command == NULL)
		return ;
	printf("name = %s\n", command->name);
	while (command->args[count] != NULL)
		printf("args %i = %s\n", count, command->args[count]);
	while (command->infile[count].name != NULL)
		printf("infile %i = %s\n", count, command->infile[count].name);
	while (command->outfile[count].name != NULL)
		printf("outfile %i = %s\n", count, command->outfile[count].name);
}
