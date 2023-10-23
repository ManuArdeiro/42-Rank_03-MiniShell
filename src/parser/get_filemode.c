#include "minishell.h"

int	ft_get_filemode(t_token token)
{
	if (token == tk_dblgrt)
		return (O_APPEND);
	else if (token == tk_grt)
		return (O_RDWR);
	else if (token == tk_less)
		return (O_RDONLY);
	else if (token == tk_dblless)
		return (O_HEREDOC);
}