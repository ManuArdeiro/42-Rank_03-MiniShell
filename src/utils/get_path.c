/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:46:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 19:48:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_localpath(void)
{
	char	localdir[PATH_MAX];

	if (getcwd(localdir, sizeof(localdir)) == NULL)
		return (NULL);
	return (localdir);
}