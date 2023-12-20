/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:45:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:43:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chrcount(const char *string, int c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (string)
	{
		while (string[i] != 0)
		{
			if (string[i] == (char)c)
				count++;
			i++;
		}
	}
	return (count);
}
