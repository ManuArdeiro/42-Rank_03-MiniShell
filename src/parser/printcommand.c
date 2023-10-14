/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 15:56:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_filearray(t_file *filearray)
{
	int	count;

	count = 0;
	if (filearray == NULL)
		return ;
	while (filearray[count].name != NULL)
	{
		printf("File[%d] -> %s\n", count, filearray[count].name);
		count++;
	}
}

static void	ft_printarray(void *array, t_casttype type)
{
	char	**strarray;
	int		count;

	if (array == NULL)
	{
		printf("%s\n", NULL);
		return ;
	}
	count = 0;
	if (type == TYPE_STRING)
	{
		strarray = (char **)array;
		while (strarray[count] != NULL)
		{
			printf("argument[%d] -> %s\n", count, strarray[count]);
			count++;
		}
	}
	else if (type == TYPE_FILE)
		ft_print_filearray((t_file *)array);
}

void	ft_printcommand(t_command *command)
{
	int	count;

	count = 0;
	if (command == NULL)
		return ;
	printf("name = %s\n", command->name);
	ft_printarray(command->args, TYPE_STRING);
	ft_printarray(command->infile, TYPE_FILE);
	ft_printarray(command->outfile, TYPE_FILE);
}
