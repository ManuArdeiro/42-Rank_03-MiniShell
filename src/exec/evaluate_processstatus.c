#include "minishell.h"

int	ft_evaluate_processstatus(int status)
{
	int	exitstatus;

	exitstatus = 0;
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus != EXIT_SUCCESS)
		{
			printf("Process Exited with status -> %d \n", exitstatus);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
