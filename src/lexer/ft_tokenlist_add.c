#include "minishell.h"

void	ft_tokenlist_add(t_part **tokenlist, t_part *newtoken)
{
	t_part	*last;

	if (*tokenlist == NULL)
		tokenlist = newtoken;
	else
	{
		last = (*tokenlist);
		while (last->next != NULL)
			last = last->next;
		last->next = newtoken;	
	}
}