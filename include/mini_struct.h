/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/18 20:28:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCT_H
# define MINI_STRUCT_H

typedef enum s_bool
{
	EXIT = -1,
	FALSE,
	TRUE,
	OVERWRITE_VALUE,
	ADD_VALUE
}			t_bool;

typedef struct s_dict	t_dict;

struct s_dict
{
	char	*key;
	char	*value;
};

#endif