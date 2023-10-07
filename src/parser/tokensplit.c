#include "minishell.h"

t_mininode	*ft_create_mininode(void *content, t_nodetype type)
{
	t_mininode	*newnode;
	
	newnode = NULL;
	if (content)
	{
		newnode = malloc(sizeof(t_mininode));
		if (!newnode)
			return (NULL);
		newnode->content = content;
		newnode->type = type;
	}
	return (newnode);
}

t_list	*ft_tokensplit(
	t_part *tokenlist, void (*splitfunction)(t_token), t_nodetype nodetype)
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
			mininode = ft_create_mininode((t_list *) newlist, nodetype); 
			ft_lstinsert(&listsarray, (t_mininode *)mininode, BACK);
		}
		node = node->next;
	}
	return (listsarray);
}
