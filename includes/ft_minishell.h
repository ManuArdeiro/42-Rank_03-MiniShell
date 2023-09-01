/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/01 18:51:33 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define VARIABLE 		0

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_test
{
	int	x;
	int	y;
}	t_test;

//	File mem.c
int			main(int argc, char **argv);

#endif