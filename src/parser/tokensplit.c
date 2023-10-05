#include "minishell.h"

//FIXME -> Add Mininode function
t_part	**ft_tokensplit(t_part *tokenlist, void (*splitfunction)(t_token))
{
	t_part	*node;
	t_part	*newlist;
	t_list	*listsarray;

	if (tokenlist == NULL)
		return (NULL);
	listsarray = malloc(sizeof(t_part *));
	if (!listsarray)
		return (NULL);
	node = tokenlist;
	newlist = NULL;
	listsarray = NULL;
	while (node != NULL)
	{
		if ((*splitfunction)(node->token) == TRUE && node->used == FALSE)
		{
			node->used = TRUE;
			ft_copy_tokenlist(&newlist, tokenlist, node);
			mininode = ft_create_mininode((t_list *) newlist); 
			ft_lstinsert(&listsarray, (t_mininode *)mininode, BACK);
		}
		node = node->next;
	}
	return (listsarray);
}
