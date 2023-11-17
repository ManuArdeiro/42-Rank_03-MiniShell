#include "minishell.h"

t_token	ft_get_tokenpair(t_token token)
{
	if (token == tk_lprnths)
		return (tk_rprnths);
	else if (token == tk_dblquot)
		return (tk_dblquot);
	else if (token == tk_sglquot)
		return (tk_sglquot);
	return (token);
}
