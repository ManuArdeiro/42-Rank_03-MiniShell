/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/19 20:30:27 by jolopez-         ###   ########.fr       */
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