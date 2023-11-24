#include "minishell.h"

void	ft_lst_nodejoin(t_list *prev_node, t_list *node)
{	
	char	*string;
	t_list	*pointer;

	pointer = NULL;
	if (prev_node != NULL && node != NULL)
	{
		string = ft_strtrim((char *)prev_node->content, "\"");
		if (string != NULL)
		{
			prev_node->next = node->next;
			ft_free_string(prev_node->content);
			prev_node->content = ft_strjoin_get(string, (char *)node->content);
			ft_free_string(node->content);
			free(node);
		}
	}
	else
	{
		string = ft_strtrim((char *)node->content, "\"");
		if (string != NULL)
		{
			ft_free_string(node->content);
			if (node->next != NULL)
			{
				pointer = node->next->next;
				node->content = ft_strjoin_get(string, (char *)node->next->content);
				ft_free_string(node->next->content);
				free(node->next);
				node->next = pointer;
			}
		}
	}
}
