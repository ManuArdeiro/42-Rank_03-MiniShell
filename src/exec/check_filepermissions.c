/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filepermissions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:00:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/04 18:51:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_filepermissions(
		t_file *infile, t_file *outfile, const char *errorstr)
{
	if (outfile != NULL && ft_strequal(errorstr, NO_SUCH_FILE_OUT) == TRUE)
	{
		if (ft_strequal(outfile->name, MINISTD) == FALSE
			&& (access(outfile->name, R_OK) != 0
				|| access(outfile->name, W_OK) != 0))
			ft_print_commanderror(outfile->name, PERMISSION_DENIED);
		else
			ft_print_commanderror(outfile->name, NO_SUCH_FILE);
	}
	else if (infile != NULL && ft_strequal(errorstr, NO_SUCH_FILE_IN) == TRUE)
	{
		if (ft_strequal(infile->name, MINISTD) == FALSE
			&& access(infile->name, R_OK) != 0)
			ft_print_commanderror(infile->name, PERMISSION_DENIED);
		else
			ft_print_commanderror(infile->name, NO_SUCH_FILE);
	}
}
