/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearsummary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:21:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/21 20:22:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clearsummary(void *content)
{
	t_summarizer	*summary;

	if (content == NULL)
		return ;
	summary = (t_summarizer *)content;
	if (summary)
		free(summary);
}
