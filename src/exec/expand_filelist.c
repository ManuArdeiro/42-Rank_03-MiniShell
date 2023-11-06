#include "minishell.h"

void	ft_expand_filelist(t_list **filelist)
{
	t_list	*node;

	if (filelist == NULL)
		return ;
	node = *filelist;
	while (node != NULL)
	{
		if (((t_file *)node->content)->mode == O_APPEND)
			ft_get_heredoc(&((t_file *)(node->content))->name);
		node = node->next;
	}
}
