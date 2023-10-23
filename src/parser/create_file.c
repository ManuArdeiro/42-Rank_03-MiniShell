#include "minishell.h"

t_file	*ft_create_file(const char *name, int std_stream, int mode)
{
	t_file	*newfile;

	if (name == NULL)
		return (NULL);
	newfile = malloc(sizeof(t_file));
	if (!newfile)
		return (NULL);
	newfile->name = name;
	newfile->fd = std_stream;
	newfile->mode = mode;
}
