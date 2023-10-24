#include "minishell.h"

int	ft_create_subprocess(
		t_command *command, pid_t **pid, t_global *global)
{
	int		count;
	int		pidcount;
	char	**envp;

	count = 0;
	//get argument string array
	///get file array
	pidcount = ft_lstsize(command->outfile);
	if (pidcount == 0)
		pidcount = 1;
	*pid = malloc(sizeof(pid_t) * pidcount);
	if (!*pid)
		return (0);
	envp = ft_lstconvert_strarr(global->envlist);
	while (count < pidcount)
	{
		(*pid)[count] = fork();
		if ((*pid)[count] == 0)
			ft_execute(
				command, command->infile[0], command->outfile[count], global);	
		else if ((*pid)[count] < 0)
			ft_printerror(NULL, "Fork");
		++count;
	}
	return (pidcount);
}
