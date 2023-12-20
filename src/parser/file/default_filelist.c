/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_filelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:24:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:57:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_default_filelist(int std_stream)
{
	t_list	*newfilelist;
	t_file	*file;

	newfilelist = NULL;
	file = ft_create_file("STD", std_stream, 0);
	ft_lstinsert(&newfilelist, (t_file *)file, BACK);
	return (newfilelist);
}
