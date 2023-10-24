#include "minishell.h"

void	ft_execute_subprocess(
	t_command *command, t_file infile, t_file outfile, t_global *global)
{
	//extract env
	if (infile.name != NULL)
		infile.fd = ft_openfile(infile.name, infile.mode);
	if (outfile.name != NULL)
		outfile.fd = ft_openfile(outfile.name, outfile.mode);
	ft_duplicate_descriptors(&infile.fd, &outfile.fd);
	ft_closefile(&infile.fd);
	ft_closefile(&outfile.fd);
	if (ft_isbuiltin(command->name) == TRUE)
	{
		if (ft_builtins(command->args, global->envlist, global) == EXIT_FAILURE)
		{
			ft_printerror(NULL, "No such file or directory");
			exit(127);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		if (execve(command->name, command->args, envp) < 0)
		{
			ft_printerror(NULL, "No such file or directory");
			exit(127);
		}
	}
}
