#include "minishell.h"

void	ft_delete_filenode(t_list **filelist, char *file_todelete)
{
	t_list	*node;
	t_file	*file;
	t_list	*prevnode;

	if (filelist == NULL)
		return ;
	node = *filelist;
	prevnode = NULL;
	while (node != NULL)
	{
		file = (t_file *)node->content;
		if (ft_strequal(file->name, file_todelete) == TRUE)
		{
			prevnode->next = node->next;
			ft_freefile(node->content);
			free(node);
			return ;

		}
		prevnode = node;
		node = node->next;
	}
}
