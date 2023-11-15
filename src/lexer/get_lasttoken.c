#include "minishell.h"

t_part	*ft_get_lasttoken(t_part *tokenlist)
{
	t_part	*last;

	if (tokenlist == NULL)
		return (NULL);
	last = tokenlist;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
