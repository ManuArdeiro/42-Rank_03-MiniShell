#include "minishell.h"

int	ft_check_name_in_dict(t_list *envlist, const char *key)
{
	t_list	*node;
	size_t	len;

	if (!key || !envlist)
		return (FALSE);
	len = ft_strlen(key);
	node = envlist;
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->key, key, len) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}
//NOTE - Search dict -> To find a value/ to modify a value/ To Delete a value
void	ft_cleardict(void *content)
{
	t_dict	*dict;

	if (content == NULL)
		return ;
	dict = (t_dict *)content;
	free(dict->key);
	free(dict->value);
}

void	ft_modifydict(t_list **envlist, char *newvalue)
{

}

int	ft_searchdict(t_list *list, char *key)
{
	t_list	*node;
	size_t	len;

	if (!list || !key)
		return (EXIT);
	node = list;
	len = ft_strlen(key);
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->key, key, len) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}
