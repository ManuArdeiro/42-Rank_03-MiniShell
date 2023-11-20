/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closepipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:17:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/20 20:18:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_closepipe(int *input, int *output)
{
	ft_closefile(input);
	ft_closefile(output);
}
