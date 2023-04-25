#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->file = NULL;
	info->args = NULL;
	info->dir = NULL;
	info->num_args = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->prog_name = av[0];
	if (info->file)
	{
		info->args = strtow(info->arg, " \t");
		if (!info->args)
		{

			info->args = malloc(sizeof(char *) * 2);
			if (info->args)
			{
				info->args[0] = _strdup(info->file);
				info->args[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->args[i]; i++)
			;
		info->num_args = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->args);
	info->args = NULL;
	info->dir = NULL;
	if (all)
	{
		if (!info->command_buffer)
			free(info->file);
		if (info->env_var)
			free_list(&(info->env_var));
		if (info->history_list)
			free_list(&(info->history_list));
		if (info->alias_list)
			free_list(&(info->alias_list));
		ffree(info->environment);
			info->environment = NULL;
		bfree((void **)info->command_buffer);
		if (info->read_file_descriptor > 2)
			close(info->read_file_descriptor);
		_putchar(BUF_FLUSH);
	}
}
