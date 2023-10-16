#include "minishell.h"

char	*ft_add_pathprefix(char *commandname, t_list *envlist)
{
	char	**pathlist;
	char	*path;
	int		count;
	char	*buffer;

	count = 0;
	buffer = NULL;
	path = ft_getenv("PATH", envlist);
	pathlist = ft_split(path, ':');
	while (pathlist[count] != NULL)
	{
		buffer = ft_strjoin(pathlist[count], commandname);
		if (access(buffer, X_OK) == 0)
		{
			free(commandname);
			return (buffer);
		}
		free(buffer);
		++count;
	}
	free(path);
	ft_clear_strarray(pathlist);
	return (commandname);
}
