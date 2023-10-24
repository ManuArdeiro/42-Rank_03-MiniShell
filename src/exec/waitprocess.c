#include "minishell.h"

int	ft_waitprocess(pid_t *pid, int pidcount)
{
	int	count;
	int	status;
	int	laststatus;

	status = EXIT_SUCCESS;
	laststatus = EXIT_SUCCESS;
	if (pidcount == 0)
		pidcount = 1;
	count = 0;
	while (count < pidcount)
	{
		if (waitpid(pid[count], &status, EXIT_SUCCESS) < 0)
		{
			laststatus = ft_eval_processstatus(status);
			return (laststatus);
		}
		++count;
	}
	return (laststatus);
}
