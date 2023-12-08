/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:13:54 by Ardeiro           #+#    #+#             */
/*   Updated: 2023/12/06 18:19:22 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_double_quots(char **new_args, int *i, int *j)
{
    
}


char    **ft_join_args(t_list *envList, char *new_line)
{
    int     i;
    int     j;
    char    *temp;

    i = 1;
    j = 0;
    temp = ft_strnstr(new_line, "export ", ft_strlen(new_line) + 1);
    while (temp[i] != '\0')
    {
        if (ft_is_space(temp, i))
            i++;
        
    }
    





    while (new_args[i])
    {
        while (new_args[i][j] != '\0')
        {
            if (new_args[i][j] == '\"')
                ft_double_quots(new_args, &i, &j);
            else if (new_args[i][j] == '\'')
                ft_simple_quots(new_args, &i, &j);
            j++;
        }
        i++;
    }
    return (new_args);
}
