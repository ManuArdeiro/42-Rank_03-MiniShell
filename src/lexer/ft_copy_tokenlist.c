#include "minishell.h"

static t_part	*ft_copytoken(t_part *tokennode)
{
	t_part	*tokencopy;

	if (tokennode == NULL)
		return (NULL);
	tokencopy = malloc(sizeof(t_part));
	if (!tokencopy)
		return (NULL);
	tokencopy->end = tokennode->end;
	tokencopy->start = tokennode->start;
	tokencopy->token = tokennode->token;
	tokencopy->index = tokennode->index;
	tokencopy->used = tokennode->used;
	tokencopy->next = NULL;
	return (tokencopy);
}

void	ft_copy_tokenlist(t_part **newlist, t_part *tokenlist, t_part *limitnode)
{
	t_part	*node;
	t_part	newtoken;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != limitnode)
	{
		newtoken = ft_copytoken(node);
		ft_tokenlist_add(newlist, newtoken);
		node = node->next;
	}
}